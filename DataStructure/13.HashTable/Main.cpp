#include <iostream>
#include "HashTable.h"

int main()
{
	// �ؽ� ���̺� ��ü.
	HashTable table;

	table.Add("Ronnie", "010-123456");
	table.Add("Ronni", "010-123456");
	table.Add("Taejun", "010-123456");
	table.Add("Baker", "010-123456");
	table.Add("Ijun", "010-123456");

	table.Print();

	Pair<std::string, std::string> value;
	if (table.Find("Baker", value))
	{
		std::cout << "Ű: Baker �׸��� ã�ҽ��ϴ�.\n";
	}
	else
	{
		std::cout << "Ű: Baker �׸��� �� ã�ҽ��ϴ�.\n";
	}

	table.Delete("Ronnie");
	std::cout << "���� �� ���----\n";
	table.Print();

	std::cin.get();
}