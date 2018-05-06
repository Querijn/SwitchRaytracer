#include "SwitchFrameBuffer.h"
#if !defined(_WIN32)
extern "C" 
{
#include "orig/utils.h"
#include "lib/printk.h"
#include "display/video_fb.h"

#include "hwinit/btn.h"
#include "hwinit/i2c.h"
#include "hwinit/tsec.h"
#include "hwinit/hwinit.h"
#include "hwinit/di.h"
#include "hwinit/mc.h"
#include "hwinit/t210.h"
#include "hwinit/sdmmc.h"
#include "hwinit/sdmmc_driver.h"
#include "orig/fuse.h"
#include "orig/se.h"
#include "orig/key_derivation.h"
#include "orig/exocfg.h"
#include "orig/smiley.h"
#include "lib/heap.h"
#include "lib/crc32.h"
#include "lib/qrcodegen.h"
#include "orig/rcm_usb.h"
}

const float t_TimerToSeconds = 1.0f / 1000000;

SwitchSurface::SwitchSurface()
{
	config_hw();
	display_enable_backlight(false);
	display_init();

	// Set up the display, and register it as a printk provider.
	m_FrameBuffer = display_init_framebuffer();
	video_init(m_FrameBuffer);

	//Tegra/Horizon configuration goes to 0x80000000+, package2 goes to 0xA9800000, we place our heap in between.
	heap_init(0x90020000);

	/* Turn on the backlight after initializing the lfb */
	/* to avoid flickering. */
	display_enable_backlight(true); 
	
	m_LastTimer = TMR(0x10);
}

SwitchSurface::~SwitchSurface()
{
	const uint8_t MAX77620_I2C_PERIPH = I2C_5;
	const uint8_t MAX77620_I2C_ADDR = 0x3C;

	const uint8_t MAX77620_REG_ONOFFCNFG1 = 0x41;
	//const uint8_t MAX77620_REG_ONOFFCNFG2 = 0x42;

	//const uint8_t MAX77620_ONOFFCNFG1_SFT_RST = 1u << 7;
	const uint8_t MAX77620_ONOFFCNFG1_PWR_OFF = 1u << 1;

	uint8_t regVal = i2c_recv_byte(MAX77620_I2C_PERIPH, MAX77620_I2C_ADDR, MAX77620_REG_ONOFFCNFG1);
	regVal |= MAX77620_ONOFFCNFG1_PWR_OFF;
	i2c_send_byte(MAX77620_I2C_PERIPH, MAX77620_I2C_ADDR, MAX77620_REG_ONOFFCNFG1, regVal);
}

void SwitchSurface::OutputToScreen()
{
	u32 t_CurrentTimer = TMR(0x10);
	u32 t_DeltaTime = t_CurrentTimer - m_LastTimer;
	m_DeltaTime = t_DeltaTime * t_TimerToSeconds;

	m_LastTimer = t_CurrentTimer;
}

bool SwitchSurface::ShouldShutdown() const
{
	return (btn_read() == BTN_POWER);
}

double SwitchSurface::GetDeltaTime() const
{
	return m_DeltaTime;
}
#endif