#pragma once

#include <glm/glm.hpp>

struct Ray;

class Primitive
{
public:
	Primitive(const glm::vec3& a_Position);

	virtual bool Intersects(const Ray& a_Hit) const = 0;

protected:
	glm::vec3 m_Position;
};