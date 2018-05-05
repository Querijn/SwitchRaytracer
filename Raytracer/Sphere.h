#pragma once

#include "Primitive.h"

class Ray;
class Sphere : public Primitive
{
public:
	Sphere(const glm::vec3& a_Position, const BaseMaterial* a_Material, float a_Radius);

	float Intersects(const Ray& a_Ray) const;

private:
	float m_Radius2;
};