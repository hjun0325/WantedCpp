#pragma once

class Rectangle
{
public:
	Rectangle(float width = 1, float height = 1);
	~Rectangle();

	// 면적 구하는 함수.
	float GetArea();

	// 둘레 구하는 함수.
	float GetSize();

private:
	float width; // 가로.
	float height; // 세로.
};