#pragma once

#include <glm/glm.hpp>

class Scene;
class Primitive;
class Ray;
struct BaseMaterial
{	
	virtual glm::vec3 GetColour(const Ray& a_Ray, const Scene& a_Scene, const Primitive* a_Primitive, float a_Distance, size_t a_Depth) const = 0;
};