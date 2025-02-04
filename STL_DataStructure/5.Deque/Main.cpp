// �� ����� ���� ��� ��Ŭ���.
#include <deque>
#include <iostream>

int main()
{
	// �� ����.
	std::deque<int> deque;

	// ������ �߰�.
	deque.emplace_back(100);
	deque.emplace_front(200);

	// ���.
	for (int ix = 0;ix < (int)deque.size();++ix)
	{
		std::cout << deque[ix]<<"\n";
	}

	// ���.
	for (auto it = deque.begin(); it != deque.end();++it)
	{
		std::cout << *it << "\n";
	}

	for (auto& value : deque)
	{

	}

	// ������ ���� �� ����.
	auto data = deque.back();
	deque.pop_back();

	std::cout << data << "\n";

	deque.clear();
	// ������� Ȯ��.
	if (deque.empty())
	{
		std::cout << "���� ������ϴ�.";
	}

	std::cin.get();
}