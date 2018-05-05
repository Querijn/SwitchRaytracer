#include "WinFrameBuffer.h"

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_timer.h>

#include <vector>
#include <chrono>
#include <thread>

#include <windows.h>

WinFrameBuffer::WinFrameBuffer()
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &m_Window, &m_Renderer);
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 0);
	SDL_RenderClear(m_Renderer);
	SDL_SetRenderDrawColor(m_Renderer, 255, 0, 0, 255);

	m_Texture = SDL_CreateTexture(m_Renderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);

	LARGE_INTEGER t_LargeInteger;
	if (!QueryPerformanceFrequency(&t_LargeInteger)) __debugbreak();

	m_Frequency = double(t_LargeInteger.QuadPart) / 1000.0;

	QueryPerformanceCounter(&t_LargeInteger);
	m_StartTime = t_LargeInteger.QuadPart;
}

WinFrameBuffer::~WinFrameBuffer()
{
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	SDL_DestroyTexture(m_Texture);
	SDL_Quit();
}

void WinFrameBuffer::SetTestData()
{
	for (unsigned int i = 0; i < 1000; i++)
	{
		const unsigned int x = rand() % SCREEN_WIDTH;
		const unsigned int y = rand() % SCREEN_HEIGHT;

		uint8_t* t_Image = GetPoint(x, y);
		t_Image[0] = 255;
		t_Image[1] = 0;
		t_Image[2] = 0;
	}
}

void WinFrameBuffer::OutputToScreen()
{
	LARGE_INTEGER t_Integer;
	QueryPerformanceCounter(&t_Integer);
	m_DeltaTime = double(t_Integer.QuadPart - m_StartTime) / m_Frequency;
	m_StartTime = t_Integer.QuadPart;

	uint8_t* t_Image = *this;
	SDL_UpdateTexture(m_Texture, NULL, t_Image, GetBytesPerScanline());

	SDL_RenderCopy(m_Renderer, m_Texture, NULL, NULL);
	SDL_RenderPresent(m_Renderer);

	double t_DesiredDelta = 1000.0 / 60.0;
	double t_SleepTime = (m_DeltaTime < t_DesiredDelta) ? t_DesiredDelta - m_DeltaTime : 0.0;
	std::this_thread::sleep_for(std::chrono::milliseconds((uint32_t)t_SleepTime));
}

bool WinFrameBuffer::ShouldShutdown() const
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			return true;
	}
	return false;
}

double WinFrameBuffer::GetDeltaTime() const
{
	return m_DeltaTime;
}
