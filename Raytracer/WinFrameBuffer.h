// The purpose of this class is to output the Framebuffer on a Windows device
#pragma once

#include "FrameBuffer.h"
#include <cstdint>

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;

class WinFrameBuffer : public FrameBuffer
{
public:
	WinFrameBuffer();
	~WinFrameBuffer();

	void SetTestData();

	void OutputToScreen() override;
	bool ShouldShutdown() const override;
	double GetDeltaTime() const;

private:
	double m_DeltaTime = 0;
	double m_Frequency = 0.0;
	int64_t m_StartTime = 0;

	SDL_Window * m_Window;
	SDL_Renderer* m_Renderer;
	SDL_Texture* m_Texture;
	void* m_Context;
};
