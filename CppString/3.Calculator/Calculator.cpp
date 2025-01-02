#include "Calculator.h"

Calculator::Calculator() {}

int Calculator::Add(int x, int y)
{
	ac++;
	return x + y;
}

float Calculator::Divide(float x, float y)
{
	dc++;
	return x / y;
}

int Calculator::Substract(int x, int y)
{
	sc++;
	return x - y;
}

int Calculator::Multiply(int x, int y)
{
	mc++;
	return x * y;
}

void Calculator::ShowOperationCount()
{
	std::cout << "µ¡¼À: " << ac << " »¬¼À: " << sc << " °ö¼À: " << mc << " ³ª´°¼À: " << dc << "\n";
}