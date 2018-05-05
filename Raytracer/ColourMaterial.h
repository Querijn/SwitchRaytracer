#pragma once

#include "BaseMaterial.h"
#include "Ray.h"

class Scene;
class Primitive;
class ColourMaterial : public BaseMaterial
{
public:
	ColourMaterial(const glm::vec3& a_Colour);
	~ColourMaterial();

	glm::vec3 GetColour(const Ray& a_Ray, const Scene& a_Scene, const Primitive* a_Primitive, float a_Distance, size_t a_Depth) const override;

private:
	glm::vec3 m_Colour;
};


