#include "Sphere.h"
#include "Ray.h"

Sphere::Sphere(const glm::vec3 & a_Position, const BaseMaterial* a_Material, float a_Radius) :
	Primitive(a_Position, a_Material), m_Radius2(a_Radius * a_Radius)
{
}

float Sphere::Intersects(const Ray & a_Ray) const
{
	glm::vec3 v = a_Ray.Origin - m_Position;
	float b = -glm::dot(v, a_Ray.Direction);
	float det = (b * b) - glm::dot(v, v) + m_Radius2;

	float t_Dist = 0.0f;

	if (det > 0)
	{
		det = sqrtf(det);
		float i1 = b - det;
		float i2 = b + det;
		if (i2 > 0)
		{
			if (i1 < 0)
			{
				t_Dist = i2;
			}
			else
			{
				t_Dist = i1;
			}
		}
	}

	return t_Dist;
}
