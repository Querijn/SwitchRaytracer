#pragma once

#include "BaseMaterial.h"

class BlinnPhongMaterial : public BaseMaterial
{
public:
	BlinnPhongMaterial(const glm::vec3& a_Colour);
	~BlinnPhongMaterial();

	glm::vec3 GetColour(const Ray& a_Ray, const Primitive* a_Primitive, float a_Distance) const override;

private:
	glm::vec3 m_Colour;
};

