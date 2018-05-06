#pragma once

#include <glm/glm.hpp>

class Light
{
public:	
	virtual float GetInfluence(const glm::vec3& a_Position) const = 0;
};