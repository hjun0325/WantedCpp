#pragma once

class Circle
{
public:
	Circle(float radius = 1);
	~Circle();

	// ���� ���ϴ� �Լ�.
	float GetArea();

	// �ѷ� ���ϴ� �Լ�.
	float GetSize();

private:
	float radius; // ������.
	const float PI = 3.141592;
};