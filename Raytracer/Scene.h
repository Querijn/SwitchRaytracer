#pragma once

#include "Primitive.h"

#include <vector>

class Surface;
class Scene
{
public:
	Scene();
	~Scene();

	template<typename T, typename... TArgs>
	Primitive& Add(TArgs... a_Arguments)
	{
		static_assert(std::is_same<Primitive, T>::value == false && std::is_base_of<Primitive, T>::value, "Add's template parameter needs to be a class derived from Primitive!");

		T* t_AddedObject = new T(a_Arguments...);
		m_Primitives.push_back(t_AddedObject);

		return *t_AddedObject;
	}

	void Render(Surface& a_Surface) const;

private:
	std::vector<Primitive*> m_Primitives;
};
