#include <iostream>
#include "Queue.h"

int main()
{
	Queue queue;
	for (int ix = 0;ix < 10;++ix)
	{
		queue.Enqueue(ix + 10);
	}

	// ť ���.
	queue.Print();

	std::cout << "===ť ��� ����===\n";
	int value = 0;
	queue.Dequeue(value);
	queue.Dequeue(value);
	queue.Dequeue(value);

	queue.Print();

	std::cin.get();
}