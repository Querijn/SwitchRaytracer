#include "Sphere.h"
#include "Ray.h"

Sphere::Sphere(const glm::vec3 & a_Position, float a_Radius) :
	Primitive(a_Position), m_Radius(a_Radius)
{

}

bool Sphere::Intersects(const Ray & a_Ray) const
{
	return false;
}
