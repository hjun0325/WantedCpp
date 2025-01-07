#include <iostream>
#include "LinkedList.h"

#include <forward_list> //�̱� ��ũ�� ����Ʈ
#include <list> //���� ��ũ�� ����Ʈ

class Test
{
public:
	Test(int data)
		: data(data)
	{

	}

private:
	int data;
};

int main()
{
	std::forward_list<int> flist;
	flist.push_front(10);
	flist.push_front(5);
	auto position = flist.begin();
	++position;
	flist.insert_after(flist.begin(), 10);

	LinkedList<float> list;

	list.Insert(10);
	list.Insert(20);
	list.Insert(30);
	list.Insert(40);
	list.Insert(50);

	std::cout << "-----����Ʈ ������ ���-----\n";
	list.Print();

	list.Delete(30);
	list.Delete(50);

	list.Delete(60);
	list.Delete(5);

	std::cout << "-----������ ���� �� ���-----\n";
	list.Print();

	std::cin.get();
}