#pragma once
#include "FrameBuffer.h"

class SwitchFrameBuffer : public FrameBuffer
{
public:
	SwitchFrameBuffer();
	~SwitchFrameBuffer();

	void OutputToScreen() override;
	bool ShouldShutdown() const override;

	double GetDeltaTime() const override;
private:
	unsigned int* m_FrameBuffer = nullptr;
	unsigned int m_LastTimer;
	float m_DeltaTime = 0.0f;
};

