#pragma once

#include "Light.h"

class AreaLight : public Light
{
public:
	AreaLight(const glm::vec3& a_Position);
	~AreaLight();

	float GetInfluence(const glm::vec3& a_Position) const override;
	glm::vec3 GetPosition() const;
private:
	glm::vec3 m_Position;
};