#pragma once

#include <glm/glm.hpp>

class Ray;
struct BaseMaterial
{	
	virtual glm::vec3 GetColour(const Ray& a_Ray, float a_Distance) const = 0;
};