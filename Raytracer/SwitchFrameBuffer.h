#pragma once
#include "FrameBuffer.h"

class SwitchSurface : public FrameBuffer
{
public:
	SwitchSurface();
	~SwitchSurface();

	void OutputToScreen() override;
	bool ShouldShutdown() const override;

	double GetDeltaTime() const override;
private:
	uint32_t* m_FrameBuffer = nullptr;
	uint32_t m_LastTimer;
	float m_DeltaTime = 0.0f;
};

