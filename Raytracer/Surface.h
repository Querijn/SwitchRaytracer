// This class is here to denote a u32 buffer to draw pixels to.
#pragma once

#include <array>
#include <cstdint>

#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 768
#define BYTES_PER_PIXEL 3

using SurfaceData = std::array<uint8_t, SCREEN_HEIGHT * SCREEN_WIDTH * BYTES_PER_PIXEL>;

class Surface
{
public:
	Surface();
	~Surface();

	uint8_t* GetPoint(uint32_t a_X, uint32_t a_Y);
	size_t GetBytesPerScanline() const;

	uint8_t* operator[](size_t a_Index);
	operator uint8_t*() const;

protected:
	SurfaceData* m_ImageData = new SurfaceData();
};

