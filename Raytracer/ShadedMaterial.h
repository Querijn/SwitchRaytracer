#pragma once

#pragma once

#include <type_traits>

#include "BaseMaterial.h"
#include "Ray.h"
#include "Primitive.h"
#include "Scene.h"
#include "AreaLight.h"

template<typename ParentMaterial, typename = std::enable_if<std::is_same<ParentMaterial, BaseMaterial>::value == false && std::is_base_of<ParentMaterial, BaseMaterial>::value>>
class ShadedMaterial : public BaseMaterial
{
public:
	template<typename... ParentArgs>
	ShadedMaterial(ParentArgs... a_Args) :
		m_Material(a_Args...)
	{

	}

	~ShadedMaterial()
	{

	}

	glm::vec3 GetColour(const Ray& a_Ray, const Scene& a_Scene, const Primitive* a_Primitive, float a_Distance, size_t a_Depth) const
	{
		if (a_Depth >= 2) return glm::vec3(0);

		glm::vec3 t_MaterialColour = m_Material.GetColour(a_Ray, a_Scene, a_Primitive, a_Distance, a_Depth);

		float t_TotalStrength = 1.0f;
		for (Light* t_BaseLight : a_Scene.GetLights())
		{
			AreaLight& t_Light = *(AreaLight*)t_BaseLight;
			glm::vec3 t_LightDir = glm::normalize(t_Light.GetPosition() - a_Primitive->GetPosition());

			// Shadow calc
			Ray t_Ray;
			t_Ray.Direction = t_LightDir;
			t_Ray.Origin = a_Ray.Origin + a_Ray.Direction * a_Distance + t_Ray.Direction; // Small epsilon
			
			t_TotalStrength *= a_Scene.Trace(t_Ray, a_Depth + 1) == false ? 1.0 : 0.5;
		}

		return t_MaterialColour * t_TotalStrength;
	}

private:
	ParentMaterial m_Material;
};