#pragma once

#include <glm/glm.hpp>

#include "BaseMaterial.h"

class Ray;

class Primitive
{
public:
	Primitive(const glm::vec3& a_Position, const BaseMaterial* a_Material);

	virtual float Intersects(const Ray& a_Hit) const = 0;
	virtual glm::vec3 GetNormal(const Ray& a_Ray, float a_Distance) const = 0;

	const BaseMaterial* GetMaterial() const;
	glm::vec3 GetPosition() const;

protected:
	const BaseMaterial* m_Material;
	glm::vec3 m_Position;
};