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
	size_t t_Width = SCREEN_WIDTH;
	size_t t_Height = SCREEN_HEIGHT;

	Ray t_Ray;
	t_Ray.Origin = glm::vec3(0);

	for (int y = -(int)(t_Height * 0.5); y <(int)(t_Height * 0.5); y++)
	{
		for (int x = -(int)(t_Width * 0.5); x <(int)(t_Width * 0.5); x++)
		{
			t_Ray.Direction = glm::normalize(glm::vec3((float)x, (float)y, 10.0f)); // TODO: Check if this is correct

			// TODO: Octree?
			for (auto t_Primitive : m_Primitives)
			{
				if (t_Primitive->Intersects(t_Ray) > 0.0f)
				{
					auto* t_Point = a_Surface.GetPoint(x + (int)(t_Width * 0.5), y + (int)(t_Height * 0.5));
					t_Point[0] = 0xFF;
					t_Point[1] = 0xFF;
					t_Point[2] = 0xFF;
				}
			}
		}
	}
}
