#include "Scene.h"

#include "Surface.h"

Scene::Scene()
{
}

Scene::~Scene()
{

}

void Scene::Render(Surface& a_Surface) const
{
	size_t t_Width = SCREEN_WIDTH * 0.5f;
	size_t t_Height = SCREEN_HEIGHT * 0.5f;
	for (int y = -(int)(t_Height * 0.5); y <(int)(t_Height * 0.5); y++)
	{
		for (int x = -(int)(t_Width * 0.5); x <(int)(t_Width * 0.5); x++)
		{
			glm::vec3 t_Direction((float)x, (float)y, 10000.0f); // TODO: Check if this is correct
			glm::normalize(t_Direction);

			// TODO: Check all objects
		}
	}
}
