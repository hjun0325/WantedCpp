#include <iostream>
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
	// �õ�(seed, ����) ����.
	srand(static_cast<unsigned int>(time(nullptr)));

	std::cout << "Randon Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Randon Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Randon Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Randon Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Randon Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Randon Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Randon Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Randon Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Randon Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Randon Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Randon Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Randon Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Randon Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Randon Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Randon Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Randon Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Randon Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Randon Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Randon Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Randon Number: " << RandomRange(3, 10) << "\n";
	std::cout << "Randon Number: " << RandomRange(3, 10) << "\n";

	std::cin.get();
}