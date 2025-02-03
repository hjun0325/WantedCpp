#include <iostream>
#include <vector>

int main()
{
	// vector ���� ����.
	std::vector<int> vector;

	// ������� Ȯ��.
	//if (vector.size() == 0)
	if(vector.empty())
	{
		std::cout << "vector�� �����.\n";
	}

	vector.reserve(100);

	// �ڷ� ����.
	for (int ix = 0;ix < 100;++ix)
	{
		//vector.push_back(ix + 1);
		vector.emplace_back(ix + 1);
	}

	// ��� ����.
	// �ݺ��ڴ� �ε��� �ȿ� ���� ���� �´�.
	for (auto it = vector.begin();it != vector.end();)
	{
		// �����ϸ� ���� ���ΰ� ������ �Ǳ� ������ �ݺ��ڸ� �ٽ� �޾Ƽ� ����ؾ� �Ѵ�.
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

	// ��� ������ �Ʒ��� ���� ������� �ϸ� �ȵ�.
	//for (int ix = 0;ix < 1000;ix += 10)
	//{
	//	// ������ ���ϴ� ��ġ�� �ݺ��� ����.
	//	auto iterator = vector.begin() + ix;

	//	// �տ��� ���� �ݺ��ڸ� Ȱ���� �迭 ���� ����.
	//	vector.erase(iterator);
	//}

	// ��� �Ұ�.
	// ���� ���� ������ �������� ��쿡�� delete�� �ؾ���.
	vector.clear();

	// ������� Ȯ��.
	// �ȿ� ���� �������� ����(capacity)�� �״�� ����.
	if (vector.empty())
	{
		std::cout << "vector�� �����.\n";
	}

	// ũ�� ����.
	vector.resize(0);

	// ���� Ȯ��.
	// ���Ҵ� ���� ���� / ���� ����ȭ.
	// �ø��°� ���ִµ� ���̴°� ������.
	vector.reserve(0);

	// ũ�� ���� �� ���.
	vector.shrink_to_fit();
	
	std::cin.get();
}