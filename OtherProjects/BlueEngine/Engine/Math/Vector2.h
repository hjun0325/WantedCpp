#pragma once

#include <string>

namespace Blue
{
	// 2���� ���� Ŭ����.
	class Vector2
	{
	public:
		//// ����ü.(������ �������� ������� �ϰ� ���� �� ���)
		//union
		//{
		//	// x��ǥ / y��ǥ.
		//	struct
		//	{
		//		float x;
		//		float y;
		//	};

		//	float data[2];
		//};

		// x��ǥ / y��ǥ.
		float x;
		float y;

		Vector2()
			: x(0.0f), y(0.0f)
		{
		}
		Vector2(float value)
			: x(value), y(value)
		{
		}
		Vector2(float x, float y)
			: x(x), y(y)
		{
		}

		// �⺻ ��.
		static const Vector2 Zero;
		static const Vector2 One;
		static const Vector2 Right;
		static const Vector2 Up;

		// (x,y) ���ڿ� ���� �Լ�.
		std::wstring ToString();

		// ���� ���ϱ�.
		float Length();
		float Dot(const Vector2& other);
		Vector2 Normalized();
		bool Equals(const Vector2& other);
	};
}