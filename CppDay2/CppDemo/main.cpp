#include<iostream>//Ȯ���ڰ� ���� ������

int main()
{
	std::cout << "Hello"; //<< ������ �����ε�

	//���ڿ�
	char name[20];
	const char* testString = "JUN";
	int length = strlen(testString);
	//�ڷ����� ���ڿ��� ����
	//��ǻ�ʹ� �����ּҿ� ũ��θ� �����
	//���ڿ��� ũ�⸦ ��? -> �׷��� strlen()�Լ��� �迭�� �������� �ٴ� '\0'�� ã��
	//"abc\0def"�ϸ� strlen �Լ��� abc������ ����
	char* testString = new char[200];
	delete[] testString; //�Ǽ��ص� ���� �����Ϸ��� �˾Ƽ� �ٲ���

	//cpp�� ���������� ����� ���� ȣȯ�� �ȵ�
}