#pragma once
#include<iostream>

class Calculator
{
public:
	Calculator();
	int Add(int x, int y);
	float Divide(float x, float y);
	int Substract(int x, int y);
	int Multiply(int x, int y);
	void ShowOperationCount();
private:
	int ac = 0, dc = 0, sc = 0, mc = 0;
};