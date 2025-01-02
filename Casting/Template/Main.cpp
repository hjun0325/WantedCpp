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

//���ø� /�̰͵� ���� ���ϱ� �����ؼ� �������� �߼� / ��ũ�ζ� �ٸ����ѵ� �̰͵� ġȯ�ϴ°�
template<typename T,int size> //Type�� T�� ���� �� / ������ typename ��ſ� class�� ��
void Swap(T& a, T& b) //�� �ٿ� ����ġ�°� �Ϲ���
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	int number1 = 10;
	int number2 = 20;

	Swap<int,10>(number1, number2); //<int>�� �־��ִ°� ����, �ڹٳ� c#�� ��������� ������������ c++�� �Ͻ������� ��ȯ�Ǵ� ��찡 ����
	std::cout << number1 << " : " << number2 << "\n";

	float number3 = 10.34f;
	float number4 = 20.43f;
	Swap<float,10>(number3, number4);
	std::cout << number3 << " : " << number4 << "\n";
}