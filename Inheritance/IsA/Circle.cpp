#include "Circle.h"
#include <iostream>

Circle::Circle(int x, int y, float redius)
	: Point(x, y), redius(redius)
{

}

Circle::~Circle()
{

}

void Circle::ShowData()
{
	std::cout << "중심 좌표: " << x << ", " << y << ")\n";
	std::cout << "반지름: " << redius << "\n";
	std::cout << "원의 넓이: " << redius * redius * 3.141592f;
}
