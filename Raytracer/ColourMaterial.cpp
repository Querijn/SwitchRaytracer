#include "ColourMaterial.h"

ColourMaterial::ColourMaterial(const glm::vec3 & a_Colour) :
	m_Colour(a_Colour)
{
}

ColourMaterial::~ColourMaterial()
{
}

glm::vec3 ColourMaterial::GetColour(const Ray& a_Colour, const Primitive* a_Primitive, float a_Distance) const
{
	return m_Colour;
}

