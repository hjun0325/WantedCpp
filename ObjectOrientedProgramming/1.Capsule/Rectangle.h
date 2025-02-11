#pragma once

class Rectangle
{
public:
	Rectangle(float width = 1, float height = 1);
	~Rectangle();

	// ���� ���ϴ� �Լ�.
	float GetArea();

	// �ѷ� ���ϴ� �Լ�.
	float GetSize();

private:
	float width; // ����.
	float height; // ����.
};