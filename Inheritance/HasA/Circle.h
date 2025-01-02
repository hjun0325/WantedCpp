#pragma once
#include"Point.h"

class Circle
{
public:
	Circle(int x, int y, float redius);
	~Circle();

	void ShowData();
private:
	Point point;
	float redius;
};