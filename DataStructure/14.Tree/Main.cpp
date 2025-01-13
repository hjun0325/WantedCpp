#include <iostream>
#include "String.h"
#include "Node.h"
#include "Tree.h"

int main()
{
	Tree<String> tree("A");
	tree.AddChild("B");
	tree.AddChild("B", "E");
	tree.AddChild("B", "F");
	tree.AddChild("B", "G");

	tree.AddChild("C");
	tree.AddChild("C", "H");

	tree.AddChild("D");
	tree.AddChild("D", "I");
	tree.AddChild("D", "J");

	// �˻� �׽�Ʈ.
	Node<String>* outNode = nullptr;
	if (tree.Find("D", &outNode))
	{
		std::cout << "��� D �˻� ����. ��� ��: " << outNode->GetCount() << "\n";
	}
	else
	{
		std::cout << "D ��� �˻� ����\n";
	}

	// ���� ��ȸ.
	std::cout << "----���� ��ȸ----\n";
	tree.PreorderTraverse();

	std::cin.get();
}