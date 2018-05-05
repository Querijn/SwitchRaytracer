#define WINDOWS
#if defined(WINDOWS)
#include "WinFrameBuffer.h"
using DefaultFrameBuffer = WinFrameBuffer;
#else 
#include "SwitchFrameBuffer.h"
using DefaultFrameBuffer = SwitchFrameBuffer;
#endif

#include "Font.h"

#include <iostream>

int main(int argc, char* argv[])
{
	DefaultFrameBuffer t_FrameBuffer;

	char text[64];

	while (!t_FrameBuffer.ShouldShutdown())
	{
		t_FrameBuffer.SetTestData();
		memset(text, ' ', 64);
		sprintf_s(text, "%2.2f FPS, Delta: %2.2f", 1000 / t_FrameBuffer.GetDeltaTime(), t_FrameBuffer.GetDeltaTime());
		Font::Draw(text, t_FrameBuffer, 0, 0);
		t_FrameBuffer.OutputToScreen();
	}
}