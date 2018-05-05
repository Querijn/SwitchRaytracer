#include "Scene.h"

#include "Ray.h"
#include "Surface.h"

Scene::Scene()
{
}

Scene::~Scene()
{

}

void Scene::Render(Surface& a_Surface) const
{
	float t_Width = SCREEN_WIDTH;
	float t_Height = SCREEN_HEIGHT;
	float fov = 60;
	float pi = 3.14159265359f;

	Ray t_Ray;
	t_Ray.Origin = glm::vec3(0);

	for (size_t y = 0; y < t_Height; y++)
	{
		for (size_t x = 0; x < t_Width; x++)
		{
			float t_Aspect = (float)t_Width / (float)t_Height;
			float t_X = (2.0f * ((x + 0.5f) / t_Width) - 1.0f) * tanf(fov / 2.0f *pi / 180.0f) * t_Aspect;
			float t_Y = (1.0f - 2.0f * ((y + 0.5f) / t_Height)) * tanf(fov / 2.0f * pi / 180.0f);

			t_Ray.Direction = glm::normalize(glm::vec3(t_X, t_Y, 1));

			// TODO: Octree?
			Primitive* t_HitPrimitive = nullptr;
			float t_LowestDistance = 9e9f;

			for (Primitive* t_Primitive : m_Primitives)
			{
				float t_Distance = t_Primitive->Intersects(t_Ray);
				if (t_Distance <= 0.0f || t_Distance > t_LowestDistance) continue;

				t_HitPrimitive = t_Primitive;
				t_LowestDistance = t_Distance;
			}

			if (t_HitPrimitive == nullptr) continue;

			auto t_Colour = t_HitPrimitive->GetMaterial()->GetColour(t_Ray, t_HitPrimitive, t_LowestDistance);
			auto* t_Point = a_Surface.GetPoint(x, y);
			t_Point[0] = (uint8_t)(0xFF * glm::clamp(t_Colour.r, 0.0f, 1.0f));
			t_Point[1] = (uint8_t)(0xFF * glm::clamp(t_Colour.g, 0.0f, 1.0f));
			t_Point[2] = (uint8_t)(0xFF * glm::clamp(t_Colour.b, 0.0f, 1.0f));
		}
	}
}
