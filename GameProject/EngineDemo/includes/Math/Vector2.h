#pragma once
#include "Core.h"

class ENGINE_API Vector2
{
public:
	Vector2(int x = 0, int y = 0);
	~Vector2() = default;

	// 연산자 오버로딩.
	Vector2 operator+(const Vector2& other);
	Vector2 operator-(const Vector2& other);
	bool operator==(const Vector2& other);
	bool operator!=(const Vector2& other);

public: //수학 라이브러리는 public으로 변수 설정을 많이 한다.
	// x좌표 / y좌표.
	int x = 0;
	int y = 0;
};