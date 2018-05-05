#pragma once

#include <cstdint>

class Surface;

namespace Font
{
	void Draw(const char* a_Text, Surface& a_Surface, uint32_t a_X, uint32_t a_Y);
}