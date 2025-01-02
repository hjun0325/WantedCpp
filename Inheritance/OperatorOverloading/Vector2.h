#pragma once

#include <iostream>

//2���� ���� Ŭ����
class Vector2
{
public:
	Vector2();
	Vector2(float x, float y=0.0f);
	//���ϱ�
	Vector2 Add(const Vector2& other);

	//���ϱ�
	Vector2 Multiply(const Vector2& other);

	//������ �����ε�
	//Ư���� �Լ�
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

//Atan2 or ����+���� ��ȯ -> ��ü ���� ���� ��