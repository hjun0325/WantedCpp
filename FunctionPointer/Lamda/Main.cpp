#include <iostream>
#include <functional> //c++ 11

//�Լ� ������
typedef void (*functionPointer)(); //�̸��� ����ó��
using usingFP = void (*)();
std::function<void()> newFunctionPointer;

int main()
{
	//Lamda �Լ� (���� �Լ�)
	//�����ϸ鼭 ȣ��
	[]() { std::cout << "Hello Lamda\n"; }();

	//���� �Լ� ����
	int count = 0;
	auto function = [&/*&count*/](/*int& count*/)/* -> float*/ //������ ĸó����
		{ 
			++count;
			//std::cout << "Hello Lamda\n";
			//return 100;
		};

	//�Լ� �����͸� ����� ���� ����
	functionPointer function2 = []() {std::cout << "Hello\n";};
	function2();

	newFunctionPointer = function2;
	newFunctionPointer();

	//ȣ��
	//auto returnValue = function();
	//std::cout << returnValue;

	//cpu�� �ڷḦ gpu���� �ѱ�� -> gpu�� �׸��� -> �����.
	//�����: �̹��� (Texture2D). -> Color[]

	function();
	function();
	//function(count);
	//function(count);

	std::cout << "Count: " << count;

	//std::cin.get();
}