// 덱 사용을 위한 헤더 인클루드.
#include <deque>
#include <iostream>

int main()
{
	// 덱 선언.
	std::deque<int> deque;

	// 데이터 추가.
	deque.emplace_back(100);
	deque.emplace_front(200);

	// 출력.
	for (int ix = 0;ix < (int)deque.size();++ix)
	{
		std::cout << deque[ix]<<"\n";
	}

	// 출력.
	for (auto it = deque.begin(); it != deque.end();++it)
	{
		std::cout << *it << "\n";
	}

	for (auto& value : deque)
	{

	}

	// 데이터 추출 후 제거.
	auto data = deque.back();
	deque.pop_back();

	std::cout << data << "\n";

	deque.clear();
	// 비었는지 확인.
	if (deque.empty())
	{
		std::cout << "덱이 비었습니다.";
	}

	std::cin.get();
}