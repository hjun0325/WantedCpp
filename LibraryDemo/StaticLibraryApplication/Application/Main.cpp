#include <iostream>

// Main.cpp -> ������ -> Main.obj
// ��Ŀ(Linker) -> Library.lib
// exe ����.

// 1��.
// ���̺귯���� class ����.
// �����Ϸ��� ���� ���ָ� �Ѿ.
// �����Ϸ��� cpp �ڵ� �ϳ��� ��.
// ��Ŀ�� obj �� ���� ������ Library�� ��.
//class Math
//{
//public:
//    static int Add(int a, int b);
//    static int Substract(int a, int b);
//    static int Multiply(int a, int b);
//    static int Divide(int a, int b);
//};

// 2��.
#include "MyMath.h"

int main()
{
	std::cout << "Hello\n";

    std::cout << "10 + 20 = " << Math::Add(10, 20) << "\n";
    std::cout << "10 - 20 = " << Math::Substract(10, 20) << "\n";
	std::cin.get();
}