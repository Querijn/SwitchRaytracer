#include "Primitive.h"
#include "Ray.h"

Primitive::Primitive(const glm::vec3 & a_Position, const BaseMaterial* a_Material) :
	m_Position(a_Position), m_Material(a_Material)
{
}

const BaseMaterial* Primitive::GetMaterial() const
{
	return m_Material;
}
