#include <iostream>
#include "BinarySearchTree.h"

int main()
{
	// ���� Ž�� Ʈ�� ����.
	BinarySearchTree<int> tree;

	// ��� �߰�.
	tree.InsertNode(50);
	tree.InsertNode(30);
	tree.InsertNode(20);
	tree.InsertNode(70);
	tree.InsertNode(100);
	tree.InsertNode(40);
	tree.InsertNode(60);
	tree.InsertNode(10);
	tree.InsertNode(90);

	std::cin.get();
}