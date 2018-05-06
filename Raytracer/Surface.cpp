#include "Surface.h"

Surface::Surface()
{
}

Surface::~Surface()
{
	delete m_ImageData;
}

uint8_t* Surface::GetPoint(uint32_t a_X, uint32_t a_Y)
{
	return this->operator[](a_Y * GetBytesPerScanline() + a_X * BYTES_PER_PIXEL);
}

size_t Surface::GetBytesPerScanline() const
{
	return SCREEN_WIDTH * BYTES_PER_PIXEL;
}

uint8_t * Surface::operator[](size_t a_Index)
{
	return m_ImageData->data() + a_Index;
}

Surface::operator uint8_t*() const
{
	return m_ImageData->data();
}
