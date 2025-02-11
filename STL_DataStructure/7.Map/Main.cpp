#include <iostream>
#include <string>
#include <map>

// ����ü.
struct Item
{
	std::string name;
	unsigned int kind = 0;
	int price = 0;
	int code = 0;
};

// ����� ���� ������ �����ε�.
std::ostream& operator<<(std::ostream& os, const Item& item)
{
	return os 
		<< "�̸�: " << item.name
		<< ", ����: " << item.price 
		<< ", �ڵ�: " << item.code;
}

int main()
{
	// �� ����.
	//std::map<std:: string, Item, std::greater<std::string>> items;
	std::map<std::string, Item> items;

	// ������ �߰�.
	items.insert({ "���", {"���", 1, 200, 0 } });
	items.insert({ "�ظ�", {"�ظ�", 1, 1000, 4 } });
	items.insert({ "����", {"����", 2, 500, 3 } });

	// ���� Ȯ�� �� ���.
	if (!items.empty())
	{
		std::cout << "����� ������ ��: " << items.size() << "\n";
	}

	// ���.
	for (auto& pair : items)
	{
		std::cout << pair.second << "\n";
	}

	// �˻�.
	auto it = items.find("�ظ�");
	if (it != items.end())
	{
		std::cout 
			<< "��� �������� �ֽ��ϴ�. �ظ��� ������ "
			<< it->second.price
			<< "�Դϴ�.\n";
	}

	// ����.
	if (it != items.end())
	{
		items.erase(it);

		std::cout << "�ظ� ������ ���� �� ���\n";
		for (auto& pair : items)
		{
			std::cout << pair.second << "\n";
		}
	}

	std::cin.get();
}
