#pragma once

#include "Primitive.h"
#include "Light.h"

#include <vector>

class Surface;
class Scene
{
public:
	Scene();
	~Scene();

	template<typename T, typename... TArgs>
	Primitive& AddPrimitive(TArgs... a_Arguments)
	{
		static_assert(std::is_same<Primitive, T>::value == false && std::is_base_of<Primitive, T>::value, "Add's template parameter needs to be a class derived from Primitive!");

		T* t_AddedPrimitive = new T(a_Arguments...);
		m_Primitives.push_back(t_AddedPrimitive);

		return *t_AddedPrimitive;
	}

	template<typename T, typename... TArgs>
	Light& AddLight(TArgs... a_Arguments)
	{
		static_assert(std::is_same<Light, T>::value == false && std::is_base_of<Light, T>::value, "Add's template parameter needs to be a class derived from Light!");

		T* t_AddedLight = new T(a_Arguments...);
		m_Lights.push_back(t_AddedLight);

		return *t_AddedLight;
	}

	bool Trace(const Ray& a_Ray, glm::vec3& a_Colour, size_t a_Depth = 0) const;
	void Render(Surface& a_Surface) const;

	std::vector<Primitive*> GetPrimitives() const;
	std::vector<Light*> GetLights() const;

private:
	std::vector<Primitive*> m_Primitives;
	std::vector<Light*> m_Lights;
};
