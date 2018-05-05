#pragma once

#include <glm/glm.hpp>

class Primitive;
class Ray;
struct BaseMaterial
{	
	virtual glm::vec3 GetColour(const Ray& a_Ray, const Primitive* a_Primitive, float a_Distance) const = 0;
};