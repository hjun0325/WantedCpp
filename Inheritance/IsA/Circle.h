#pragma once
#include"Point.h"

class Circle : public Point
{
public:
	Circle(int x, int y, float redius);
	~Circle();

	void ShowData();
private:
	float redius;
};