#include <iostream>
#include "Queue.h"

int main()
{
	Queue<int> queue;

	queue.Enqueue(10);
	queue.Enqueue(20);
	queue.Enqueue(30);
	queue.Enqueue(40);
	queue.Enqueue(50);
	queue.Enqueue(60);
	queue.Enqueue(70);
	queue.Enqueue(80);

	std::cout << "---- 데이터 추가 후 출력 ----\n";
	queue.Print();

	int outValue = 0;
	if (queue.Dequeue(outValue))
	{
		std::cout << "큐에서 출력된 값: " << outValue << "\n";
	}

	if (queue.Dequeue(outValue))
	{
		std::cout << "큐에서 출력된 값: " << outValue << "\n";
	}

	if (queue.Dequeue(outValue))
	{
		std::cout << "큐에서 출력된 값: " << outValue << "\n";
	}

	std::cout << "---- 데이터 삭제 후 출력 ----\n";
	queue.Print();

	queue.Enqueue(90);
	queue.Enqueue(100);
	queue.Enqueue(110);
	queue.Enqueue(120);
	queue.Enqueue(130);
	queue.Enqueue(140);

	std::cout << "---- 데이터 추가 후 출력 ----\n";
	queue.Print();

	std::cin.get();
}