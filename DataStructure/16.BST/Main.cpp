#include <iostream>
#include "BinarySearchTree.h"

int main()
{
	// 이진 탐색 트리 생성.
	BinarySearchTree<int> tree;

	// 노드 추가.
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