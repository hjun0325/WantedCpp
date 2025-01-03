#include <iostream>
#include <functional> //c++ 11

//함수 포인터
typedef void (*functionPointer)(); //이름을 변수처럼
using usingFP = void (*)();
std::function<void()> newFunctionPointer;

int main()
{
	//Lamda 함수 (무명 함수)
	//선언하면서 호출
	[]() { std::cout << "Hello Lamda\n"; }();

	//람다 함수 저장
	int count = 0;
	auto function = [&/*&count*/](/*int& count*/)/* -> float*/ //가려서 캡처하자
		{ 
			++count;
			//std::cout << "Hello Lamda\n";
			//return 100;
		};

	//함수 포인터를 사용한 람다 저장
	functionPointer function2 = []() {std::cout << "Hello\n";};
	function2();

	newFunctionPointer = function2;
	newFunctionPointer();

	//호출
	//auto returnValue = function();
	//std::cout << returnValue;

	//cpu가 자료를 gpu한테 넘기고 -> gpu가 그리기 -> 백버퍼.
	//백버퍼: 이미지 (Texture2D). -> Color[]

	function();
	function();
	//function(count);
	//function(count);

	std::cout << "Count: " << count;

	//std::cin.get();
}