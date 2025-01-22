#pragma once

#include "Core.h"

class ENGINE_API Timer
{
public:
	Timer();
	Timer(float time);

	void Update(float deltaTime);
	void Reset();

	inline bool IsTimeOut() const { return elapsedTime >= setTime; }
	inline void SetTime(float time) { setTime = time; }
	float getElapsedTime() { return elapsedTime; }
private:
	float elapsedTime = 0.0f;
	float setTime = 0.0f;
};