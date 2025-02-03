#include <iostream>
#include "BinarySearchTree.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // ���� Ž�� Ʈ�� ��ü�� ����.
    BinarySearchTree<int> tree;

    // ���� Ž�� Ʈ���� ��� ����.
    tree.InsertNode(50);
    tree.InsertNode(30);
    tree.InsertNode(20);
    tree.InsertNode(40);
    tree.InsertNode(70);
    tree.InsertNode(60);
    tree.InsertNode(80);
    tree.InsertNode(100);
    tree.InsertNode(120);
    tree.InsertNode(130);
    tree.InsertNode(110);
    tree.InsertNode(150);
    tree.InsertNode(170);
    tree.InsertNode(140);

    // ���� ��ȸ�� Ʈ���� ��� ��Ҹ� ���.
    tree.PreorderTraverse();

    // ���� ��ȸ�� Ʈ���� ��� ��Ҹ� ���.
    tree.InorderTraverse();

    // ���� Ž�� Ʈ������ Ư�� Ű�� �˻�.
    int keyToSearch = 60;
    if (tree.SearchNode(keyToSearch) == true)
    {
        std::cout << "�˻� ����: Ʈ���� " << keyToSearch << "�� �ֽ��ϴ�.\n";
    }
    else
    {
        std::cout << "�˻� ����: Ʈ���� " << keyToSearch << "�� �����ϴ�.\n";
    }

    // ��� ���� ����.
    int keyToDelete = 30;
    tree.DeleteNode(keyToDelete);

    std::cout << "��� " << keyToDelete << "����\n";
    tree.InorderTraverse();

    keyToDelete = 50;
    tree.DeleteNode(keyToDelete);
    std::cout << "��� " << keyToDelete << "����\n";
    tree.InorderTraverse();

    keyToDelete = 60;
    tree.DeleteNode(keyToDelete);
    std::cout << "��� " << keyToDelete << "����\n";
    tree.InorderTraverse();

    keyToDelete = 80;
    tree.DeleteNode(keyToDelete);
    std::cout << "��� " << keyToDelete << "����\n";
    tree.InorderTraverse();

    keyToDelete = 20;
    tree.DeleteNode(keyToDelete);
    std::cout << "��� " << keyToDelete << "����\n";
    tree.InorderTraverse();

    std::cin.get();
}