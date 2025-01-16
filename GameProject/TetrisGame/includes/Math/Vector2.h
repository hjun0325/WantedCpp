#pragma once
#include "Core.h"

class ENGINE_API Vector2
{
public:
	Vector2(int x = 0, int y = 0);
	~Vector2() = default;

	// ������ �����ε�.
	Vector2 operator+(const Vector2& other);
	Vector2 operator-(const Vector2& other);
	bool operator==(const Vector2& other);
	bool operator!=(const Vector2& other);

public: // ���� ���̺귯���� public���� ���� ������ ���� �Ѵ�.
	// x��ǥ / y��ǥ.
	int x = 0;
	int y = 0;
};