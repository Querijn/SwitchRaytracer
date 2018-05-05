#include "BlinnPhongMaterial.h"

#include <Windows.h>

#include "Ray.h"
#include "Primitive.h"

BlinnPhongMaterial::BlinnPhongMaterial(const glm::vec3& a_Colour, float a_SpecularHardness, float a_SpecularStrength) :
	m_Colour(a_Colour), m_SpecularHardness(a_SpecularHardness), m_SpecularStrength(a_SpecularStrength)
{

}

BlinnPhongMaterial::~BlinnPhongMaterial()
{

}

glm::vec3 BlinnPhongMaterial::GetColour(const Ray& a_Ray, const Primitive* a_Primitive, float a_Distance) const
{
	glm::vec3 t_Position = a_Primitive->GetPosition();
	glm::vec3 t_LightPosition = glm::vec3(0, 15, 0);
	glm::vec3 t_LightDir = glm::normalize(t_LightPosition - t_Position);
	glm::vec3 t_RayDir = -a_Ray.Direction;
	glm::vec3 t_HalfWay = glm::normalize(t_LightDir + t_RayDir);
	glm::vec3 t_Normal = a_Primitive->GetNormal(a_Ray, a_Distance);

	glm::vec3 t_Ambient = m_Colour * 0.05f;
	glm::vec3 t_Diffuse = m_Colour * max(dot(t_LightDir, t_Normal), 0.0f);

	glm::vec3 t_LightBounce = glm::reflect(-t_LightDir, t_Normal);
	float t_Specular = pow(max(dot(t_RayDir, t_LightBounce), 0.0), m_SpecularHardness) * m_SpecularStrength;

	return glm::vec3(t_Ambient + t_Diffuse + t_Specular);
}
