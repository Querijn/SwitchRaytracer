#include "AreaLight.h"

AreaLight::AreaLight(const glm::vec3 & a_Position) :
	m_Position(a_Position)
{

}

AreaLight::~AreaLight()
{
}

float AreaLight::GetInfluence(const glm::vec3 & a_Position) const
{
	return 1;
}

glm::vec3 AreaLight::GetPosition() const
{
	return m_Position;
}
