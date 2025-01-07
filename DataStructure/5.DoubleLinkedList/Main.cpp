#include <iostream>
#include "LinkedList.h"

// ���� �Լ�.
// �̺�Ʈ ������(Listener) �Լ�.
void OnListEmptyError()
{
    std::cout << "�����Ͱ� �����ϴ�.\n";
}

int main()
{
    LinkedList<int> list(OnListEmptyError);
    list.Delete(100);

    list.AddToFirst(10);
    list.AddToFirst(20);
    list.AddToFirst(30);
    list.AddToFirst(40);
    list.AddToFirst(50);

    std::cout << "----����Ʈ ���----\n";
    list.Print();

    list.AddToLast(100);
    list.AddToLast(90);
    list.AddToLast(80);
    list.AddToLast(70);
    list.AddToLast(60);

    std::cout << "----����Ʈ ���----\n";
    list.Print();

    list.Delete(100);
    list.Delete(30);
    list.Delete(20);
    list.Delete(60);

    std::cout << "----���� �� ����Ʈ ���----\n";
    list.Print();

    std::cin.get();
}