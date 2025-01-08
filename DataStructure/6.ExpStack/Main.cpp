#include <iostream>
#include "ExpStack.h"

int main()
{
	// ���� ��ü.
	ExpStack stack;

	std::cout << "ù ��° ���� ���� - ����ġ 140\n";
	stack.Push(140.0f);

	std::cout << "�� ��° ���� ���� - ����ġ 180\n";
	stack.Push(180.0f);

	std::cout << "�� ��° ���� ���� - ����ġ 200\n";
	stack.Push(200.0f);

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

	/*while (!stack.IsEmpty())
	{
		float value;
		if (stack.Pop(value))
		{
			std::cout << "���� ����ġ: " << value << "\n";
		}
	}*/

	std::cin.get();
}