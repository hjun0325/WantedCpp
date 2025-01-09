#include <iostream>

// Main.cpp -> 컴파일 -> Main.obj
// 링커(Linker) -> Library.lib
// exe 생성.

// 1차.
// 라이브러리용 class 제작.
// 컴파일러는 선언만 해주면 넘어감.
// 컴파일러는 cpp 코드 하나만 봄.
// 링커는 obj 다 보고 없으면 Library를 봄.
//class Math
//{
//public:
//    static int Add(int a, int b);
//    static int Substract(int a, int b);
//    static int Multiply(int a, int b);
//    static int Divide(int a, int b);
//};

// 2차.
#include "MyMath.h"

int main()
{
	std::cout << "Hello\n";

    std::cout << "10 + 20 = " << Math::Add(10, 20) << "\n";
    std::cout << "10 - 20 = " << Math::Substract(10, 20) << "\n";
	std::cin.get();
}