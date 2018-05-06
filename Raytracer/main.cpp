#if defined(_WIN32)
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
#include "BlinnPhongMaterial.h"
#include "ReflectingMaterial.h"
#include "AreaLight.h"

#include <iostream>

int main()
{
	DefaultFrameBuffer t_FrameBuffer;
	Scene t_Scene;

	auto t_Red = ReflectingMaterial<BlinnPhongMaterial>(0.1f, glm::vec3(1, 0, 0), 10.0f, 0.5f);
	auto t_Green = ReflectingMaterial<BlinnPhongMaterial>(0.1f, glm::vec3(0, 1, 0), 10.0f, 0.5f);
	auto t_Blue = ReflectingMaterial<BlinnPhongMaterial>(0.1f, glm::vec3(0, 0, 1), 10.0f, 0.5f);

	t_Scene.AddPrimitive<Sphere>(glm::vec3(-4, 0, 10), &t_Red, 2.0f);
	t_Scene.AddPrimitive<Sphere>(glm::vec3(0, 0, 10), &t_Green, 2.0f);
	t_Scene.AddPrimitive<Sphere>(glm::vec3(4, 0, 10), &t_Blue, 2.0f);

	t_Scene.AddLight<AreaLight>(glm::vec3(0, 15, 0));

	char text[64];

	while (!t_FrameBuffer.ShouldShutdown())
	{
		// Trace the rays
		t_Scene.Render(t_FrameBuffer);

		// Draw FPS in text on top of it
		sprintf_s(text, " %2.2f FPS, Delta: %2.2f ", 1000 / t_FrameBuffer.GetDeltaTime(), t_FrameBuffer.GetDeltaTime());
		Font::Draw(text, t_FrameBuffer, 0, 0);

		// Output
		t_FrameBuffer.OutputToScreen();
	}
}
