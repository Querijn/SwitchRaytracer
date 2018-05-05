#include "BlinnPhongMaterial.h"

#include <Windows.h>

#include "Ray.h"
#include "Primitive.h"

BlinnPhongMaterial::BlinnPhongMaterial(const glm::vec3& a_Colour) :
	m_Colour(a_Colour)
{

}

BlinnPhongMaterial::~BlinnPhongMaterial()
{

}

glm::vec3 BlinnPhongMaterial::GetColour(const Ray& a_Ray, const Primitive* a_Primitive, float a_Distance) const
{
	glm::vec3 t_Position = a_Primitive->GetPosition();
	glm::vec3 t_LightPosition = /*t_Position +*/ glm::vec3(0, 15, 0);
	glm::vec3 t_LightDir = glm::normalize(t_LightPosition - t_Position);
	glm::vec3 t_RayDir = -a_Ray.Direction;
	glm::vec3 t_HalfWay = glm::normalize(t_LightDir + t_RayDir);
	glm::vec3 t_Normal = a_Primitive->GetNormal(a_Ray, a_Distance);

	glm::vec3 ambient = m_Colour * 0.05f;
	glm::vec3 normal = glm::normalize(t_Normal);
	float diff = max(dot(t_LightDir, normal), 0.0);
	glm::vec3 diffuse = diff * m_Colour;

	glm::vec3 t_LightBounce = glm::reflect(-t_LightDir, normal);
	float spec = pow(max(dot(t_RayDir, t_LightBounce), 0.0), 10.0) * 0.5;

	return glm::vec3(ambient + diffuse + spec);
}
