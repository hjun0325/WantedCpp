//��ó��(Pre-Process)
//���Ͽ� ���� ������ �����ְ� �� ��ó�� �ڵ带 ���ش�
#include<iostream> 
#include"Log.h"

//void Log(const char* message);
//��ũ��->ġȯ
//#define Square(x) ((x)*(x))
#define FORCEINLINE __forceinline //getter, setter���� ���� ��
FORCEINLINE int Square(int x) //�� �� ���ϰ� �ζ��� ȣ��, �ӵ��� �������� ��ſ� �ؽ�Ʈ �뷮�� ����
{
	return x * x;
}


//������(Entry Point)
int main()
{
	//���
	//std::cout << "Hello World\n";
	//Log("Hello World");

	std::cout << Square(10) << "\n";

	//�ǹ� ���� �ٷ� ������� ����� �߰�
	std::cin.get();
}