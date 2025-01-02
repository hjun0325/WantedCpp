#pragma once

#include <iostream>

//2차원 벡터 클래스
class Vector2
{
public:
	Vector2();
	Vector2(float x, float y=0.0f);
	//더하기
	Vector2 Add(const Vector2& other);

	//곱하기
	Vector2 Multiply(const Vector2& other);

	//연산자 오버로딩
	//특별한 함수
	Vector2 operator+(const Vector2& other);
	Vector2 operator*(const Vector2& other);
	Vector2 operator-(const Vector2& other);
	bool operator==(const Vector2& other);
	bool operator!=(const Vector2& other);
	Vector2& operator += (const Vector2 & other);
	float operator[](int index);

	friend std::ostream& operator<<(std::ostream& os, const Vector2& vector) //friend?
	{
		os << "(" << vector.x << "," << vector.y << ")\n";
		return os;
	}

	//Getter/Setter
	float GetX() const;
	float GetY() const;

private:
	float x;
	float y;
};

//Atan2 or 내적+라디안 변환 -> 객체 각도 구할 때