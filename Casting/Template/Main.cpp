#include <iostream>

//void Swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void Swap(float& a, float& b)
//{
//	float temp = a;
//	a = b;
//	b = temp;
//}

//템플릿 /이것도 많이 쓰니까 복잡해서 쓰지말자 추세 / 매크로랑 다르긴한데 이것도 치환하는것
template<typename T,int size> //Type나 T를 자주 씀 / 예전엔 typename 대신에 class를 씀
void Swap(T& a, T& b) //두 줄에 나눠치는게 일반적
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	int number1 = 10;
	int number2 = 20;

	Swap<int,10>(number1, number2); //<int>를 넣어주는게 정석, 자바나 c#은 명시적으로 무조건이지만 c++은 암시적으로 변환되는 경우가 있음
	std::cout << number1 << " : " << number2 << "\n";

	float number3 = 10.34f;
	float number4 = 20.43f;
	Swap<float,10>(number3, number4);
	std::cout << number3 << " : " << number4 << "\n";
}