#pragma once

#include "BaseMaterial.h"
#include "Ray.h"

class ColourMaterial : public BaseMaterial
{
public:
	ColourMaterial(const glm::vec3& a_Colour);
	~ColourMaterial();

	glm::vec3 GetColour(const Ray& a_Ray, float a_Distance) const override;

private:
	glm::vec3 m_Colour;
};


