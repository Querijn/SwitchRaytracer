#define WINDOWS
#if defined(WINDOWS)
#include "WinFrameBuffer.h"
using DefaultFrameBuffer = WinFrameBuffer;
#else 
#include "SwitchFrameBuffer.h"
using DefaultFrameBuffer = SwitchFrameBuffer;
#endif

#include "Font.h"
#include "Scene.h"
#include "Sphere.h"
#include "ColourMaterial.h"

#include <iostream>

int main(int argc, char* argv[])
{
	DefaultFrameBuffer t_FrameBuffer;
	Scene t_Scene;

	auto t_SimpleMaterial = ColourMaterial(glm::vec3(0, 0, 1));
	auto& t_Sphere = t_Scene.Add<Sphere>(glm::vec3(0, 0, 10), &t_SimpleMaterial, 5.0f);

	char text[64];

	while (!t_FrameBuffer.ShouldShutdown())
	{
		t_Scene.Render(t_FrameBuffer);
		sprintf_s(text, " %2.2f FPS, Delta: %2.2f ", 1000 / t_FrameBuffer.GetDeltaTime(), t_FrameBuffer.GetDeltaTime());
		Font::Draw(text, t_FrameBuffer, 0, 0);
		t_FrameBuffer.OutputToScreen();
	}
}
