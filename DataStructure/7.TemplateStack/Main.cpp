#include <iostream>
#include "stack.h"
#include <stdlib.h>
#include <time.h>

// �ּ�/�ִ� �� ������ ������ ��ȯ�ϴ� �Լ�.
int RandomRange(int min, int max)
{
	// ����.
	int diff = (max - min) + 1;
	return ((rand() * diff) / (RAND_MAX + 1)) + min;
}

int main()
{
	// ���� �߻��� ����.
	srand((unsigned int)time(nullptr));

	// ���� ��ü.
	Stack<float, 3> stack;

	std::cout << "ù ��° ���� ���� - ����ġ 140\n";
	stack.Push((float)RandomRange(10, 300));

	std::cout << "�� ��° ���� ���� - ����ġ 180\n";
	stack.Push((float)RandomRange(10, 300));

	std::cout << "�� ��° ���� ���� - ����ġ 200\n";
	stack.Push((float)RandomRange(10, 300));

	if (stack.Push(300.0f))
	{
		std::cout << "�� ��° ���� ���� - ����ġ 300\n";
	}

	// ���.
	int count = stack.Count();
	for (int ix = 0;ix < count;++ix)
	{
		float value;
		if (stack.Pop(value))
		{
			std::cout << "���� ����ġ: " << value << "\n";
		}
	}
}