#pragma once

#include "BaseMaterial.h"

class BlinnPhongMaterial : public BaseMaterial
{
public:
	BlinnPhongMaterial(const glm::vec3& a_Colour, float a_SpecularHardness, float a_SpecularStrength);
	~BlinnPhongMaterial();

	glm::vec3 GetColour(const Ray& a_Ray, const Scene& a_Scene, const Primitive* a_Primitive, float a_Distance, size_t a_Depth) const override;

private:
	glm::vec3 m_Colour;
	float m_SpecularHardness, m_SpecularStrength;
};

