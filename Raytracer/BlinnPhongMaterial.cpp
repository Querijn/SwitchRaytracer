#include "BlinnPhongMaterial.h"

#include <algorithm>

#include "Ray.h"
#include "Primitive.h"
#include "Scene.h"
#include "AreaLight.h"

BlinnPhongMaterial::BlinnPhongMaterial(const glm::vec3& a_Colour, float a_SpecularHardness, float a_SpecularStrength) :
	m_Colour(a_Colour), m_SpecularHardness(a_SpecularHardness), m_SpecularStrength(a_SpecularStrength)
{

}

BlinnPhongMaterial::~BlinnPhongMaterial()
{

}

glm::vec3 BlinnPhongMaterial::GetColour(const Ray& a_Ray, const Scene& a_Scene, const Primitive* a_Primitive, float a_Distance, size_t a_Depth) const
{
	glm::vec3 t_Position = a_Primitive->GetPosition();
	glm::vec3 t_RayDir = -a_Ray.Direction;
	glm::vec3 t_Normal = a_Primitive->GetNormal(a_Ray, a_Distance);

	float t_Specular = 0;
	float t_DiffuseS = 0;
	for (Light* t_BaseLight : a_Scene.GetLights())
	{
		AreaLight& t_Light = *(AreaLight*)t_BaseLight;
		glm::vec3 t_LightDir = glm::normalize(t_Light.GetPosition() - t_Position);
		glm::vec3 t_LightBounce = glm::reflect(-t_LightDir, t_Normal);
		glm::vec3 t_HalfWay = glm::normalize(t_LightDir + t_RayDir);

		t_Specular += pow(std::max(dot(t_RayDir, t_LightBounce), 0.0f), m_SpecularHardness) * m_SpecularStrength;
		t_DiffuseS += std::max(dot(t_LightDir, t_Normal), 0.0f);

	}
	
	return m_Colour * glm::vec3(0.05f + t_DiffuseS) + t_Specular;
}