#pragma once

#ifdef BUILD_DLL
#define MATH_DLL __declspec(dllexport)
#else
#define MATH_DLL __declspec(dllimport)
#endif

// dllimport
class MATH_DLL Math
{
public:
	static int Add(int a, int b);
	static int Substract(int a, int b);
	static int Multiply(int a, int b);
	static int Divide(int a, int b);
};