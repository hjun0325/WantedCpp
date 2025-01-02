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
	std::cout << "�߽� ��ǥ: " << x << ", " << y << ")\n";
	std::cout << "������: " << redius << "\n";
	std::cout << "���� ����: " << redius * redius * 3.141592f;
}
