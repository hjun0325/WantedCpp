#pragma once

#include <string>

namespace Blue
{
	// 2차원 벡터 클래스.
	class Vector2
	{
	public:
		//// 공용체.(접근을 여러가지 방법으로 하고 싶을 때 사용)
		//union
		//{
		//	// x좌표 / y좌표.
		//	struct
		//	{
		//		float x;
		//		float y;
		//	};

		//	float data[2];
		//};

		// x좌표 / y좌표.
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

		// 기본 값.
		static const Vector2 Zero;
		static const Vector2 One;
		static const Vector2 Right;
		static const Vector2 Up;

		// (x,y) 문자열 생성 함수.
		std::wstring ToString();

		// 길이 구하기.
		float Length();
		float Dot(const Vector2& other);
		Vector2 Normalized();
		bool Equals(const Vector2& other);
	};
}