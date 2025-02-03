#include <iostream>
#include <vector>

int main()
{
	// vector 변수 선언.
	std::vector<int> vector;

	// 비었는지 확인.
	//if (vector.size() == 0)
	if(vector.empty())
	{
		std::cout << "vector가 비었음.\n";
	}

	vector.reserve(100);

	// 자료 삽입.
	for (int ix = 0;ix < 100;++ix)
	{
		//vector.push_back(ix + 1);
		vector.emplace_back(ix + 1);
	}

	// 요소 삭제.
	// 반복자는 인덱스 안에 값을 갖고 온다.
	for (auto it = vector.begin();it != vector.end();)
	{
		// 삭제하면 벡터 내부가 변경이 되기 때문에 반복자를 다시 받아서 사용해야 한다.
		it = vector.erase(it);
		it += 9;
	}

	// TArray / std::vector
	//size_t size = vector.size();
	for (int ix = 0; ix < (int)vector.size();++ix)
	{
		std::cout << vector[ix] << " ";
	}
	//auto test = vector[10];

	// 요소 삭제를 아래와 같은 방식으로 하면 안됨.
	//for (int ix = 0;ix < 1000;ix += 10)
	//{
	//	// 삭제를 원하는 위치의 반복자 저장.
	//	auto iterator = vector.begin() + ix;

	//	// 앞에서 구한 반복자를 활용해 배열 원소 삭제.
	//	vector.erase(iterator);
	//}

	// 모두 소거.
	// 내부 저장 변수가 포인터인 경우에는 delete를 해야함.
	vector.clear();

	// 비었는지 확인.
	// 안에 값은 지우지만 공간(capacity)는 그대로 유지.
	if (vector.empty())
	{
		std::cout << "vector가 비었음.\n";
	}

	// 크기 조정.
	vector.resize(0);

	// 공간 확보.
	// 재할당 방지 목적 / 공간 최적화.
	// 늘리는건 해주는데 줄이는건 안해줌.
	vector.reserve(0);

	// 크기 줄일 때 사용.
	vector.shrink_to_fit();
	
	std::cin.get();
}