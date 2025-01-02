#include<iostream>
#include "Circle.h"

int main()
{
	//원의 x,y 위치는 (3,5)
	//반지름은 2.5
	Circle circle(3, 5, 2.5f);
	circle.ShowData();
}