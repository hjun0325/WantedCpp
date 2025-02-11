#pragma once

class Circle
{
public:
	Circle(float radius = 1);
	~Circle();

	// 면적 구하는 함수.
	float GetArea();

	// 둘레 구하는 함수.
	float GetSize();

private:
	float radius; // 반지름.
	const float PI = 3.141592;
};