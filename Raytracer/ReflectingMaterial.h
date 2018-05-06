#pragma once

#include <type_traits>

#include "BaseMaterial.h"
#include "Ray.h"
#include "Primitive.h"
#include "Scene.h"

template<typename ParentMaterial, typename = std::enable_if<std::is_same<ParentMaterial, BaseMaterial>::value == false && std::is_base_of<ParentMaterial, BaseMaterial>::value>>
class ReflectingMaterial : public BaseMaterial
{
public:
	template<typename... ParentArgs>
	ReflectingMaterial(float a_ReflectionWeight = 0.5f, float a_MaxDepth = 2, ParentArgs... a_Args) : 
		m_Material(a_Args...), m_ReflectionWeight(a_ReflectionWeight), m_MaxDepth(a_MaxDepth)
	{

	}

	~ReflectingMaterial()
	{

	}
	
	glm::vec3 GetColour(const Ray& a_Ray, const Scene& a_Scene, const Primitive* a_Primitive, float a_Distance, size_t a_Depth) const
	{
		if (a_Depth >= m_MaxDepth) return glm::vec3(0);

		glm::vec3 t_Normal = a_Primitive->GetNormal(a_Ray, a_Distance);

		Ray t_Reflect;
		t_Reflect.Origin = a_Ray.Origin + a_Ray.Direction * a_Distance * 0.995f;
		t_Reflect.Direction = glm::reflect(a_Ray.Direction, t_Normal);
		
		glm::vec3 t_MaterialColour = m_Material.GetColour(a_Ray, a_Scene, a_Primitive, a_Distance, a_Depth);
		glm::vec3 t_ReflectColour;
		if (a_Scene.Trace(t_Reflect, t_ReflectColour, a_Depth + 1))
			return (t_ReflectColour * m_ReflectionWeight + t_MaterialColour * (1.0f - m_ReflectionWeight));

		return t_MaterialColour;
	}

private:
	ParentMaterial m_Material;
	float m_ReflectionWeight;
	float m_MaxDepth;
};

