#pragma once

#include "Surface.h"

class FrameBuffer : public Surface
{
public:
	FrameBuffer();
	~FrameBuffer();

	virtual void OutputToScreen() = 0;
	virtual bool ShouldShutdown() const = 0;
};

