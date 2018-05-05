#pragma once

#include "Primitive.h"

struct Ray;
class Sphere : public Primitive
{
public:
	Sphere(const glm::vec3& a_Position, float a_Radius);

	float Intersects(const Ray& a_Ray) const;

private:
	float m_Radius2;
};