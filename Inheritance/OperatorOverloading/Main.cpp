#include "Vector2.h"

//std::ostream& operator<<(std::ostream& os, const Vector2& vector)
//{
//	os << "(" << vector.GetX() << "," << vector.GetY() << ")\n";
//	return os;
//}

int main()
{
	//Vector2 postition(4.0f, 4.0f);
	//Vector2 speed(0.5f, 0.5f);

	////Vector2 result = postition.Multiply(speed);
	//Vector2 result = postition * speed; //연산자 오버로딩을 통해 가능하게 만듬
	////Vector2 result = postition.operator*(speed); //연산자 오버로딩의 실체
	//result[0];
	//std::cout << result << "\n";
	//------------------------------------------------------
	/*Vector2 position1 = Vector2(4.0f, 3.0f);
	Vector2 position2 = Vector2(2.0f, 1.0f);
	Vector2 direction = position1 - position2;
	std::cout << direction << "\n";*/
	//------------------------------------------------
	/*Vector2 position1 = Vector2(3.0f, 1.0f);
	Vector2 position2 = Vector2(3.0f, 1.0f);
	Vector2 position3 = Vector2(5.0f, 10.0f);

	if (position1 == position2)
	{
		std::cout << "position1과 position2는 같다.\n";
	}
	else
	{
		std::cout << "position1과 position2는 다르다.\n";
	}

	if (position2 != position3)
	{
		std::cout << "position2와 position3은 다르다.\n";
	}
	else
	{
		std::cout << "position2와 position3은 같다.\n";
	}*/
	//-----------------------------------------------
	Vector2 position = Vector2(4.0f, 3.0f);
	Vector2 direction = Vector2(1.0f, 1.0f);
	Vector2 a = Vector2(3.0f, 4.0f);
	position += position += direction;
	std::cout << position << "\n";

	std::cin.get();
}