#pragma once

#include "Node.h"

// ���� Ž�� Ʈ�� Ŭ����.
template<typename T>
class BinarySearchTree
{
public:
	BinarySearchTree()
		: root(nullptr)
	{

	}

	~BinarySearchTree()
	{
		// ��� ���� �Լ� ȣ��.
	}

	// �˻�.
	// (����) �޼ҵ�(Method)/�Լ� - �޽��� (�������̽�/��������).
	// ���� / ������.
	bool SearchNode(const T& data)
	{
		// ��Ʈ���� ��������� �˻�.
		return SearchNodeRecursive(root, data);
	}
	
	// ����.
	// ��Ģ->
	// 0. �ߺ� ������� ����.
	// 1. ����->��Ʈ�������� �� ����.
	// 1-1. ��Ʈ�� ��� ������ �� ��带 ��Ʈ�� ����.
	// 2. ���� �߰��ϴ� ���� �� ��庸�� ������ ���� ���� Ʈ���� �񱳸� �̾��.
	// 3. ���� �߰��ϴ� ���� �� ��庸�� ũ�� ������ ���� Ʈ���� �񱳸� �̾��.
	bool InsertNode(const T& newData)
	{
		// �ߺ��� ������� �ʱ� ������ �̹� ������ ����.
		if (SearchNode(newData))
		{
			// ���� �޽��� ���.
			std::cout << "Error: �̹� �ߺ��� ���� �־� �߰� �Ұ���\n";
			return false;
		}

		// case1. ��Ʈ�� null.
		if (root == nullptr)
		{
			// ��Ʈ ���� �� ����.
			root = new Node<T>(newData, nullptr);
			return true;
		}

		// case2/3. ��� �Լ��� ó��.
		root = InsertNodeRecursive(root, nullptr, newData);
		return true;
	}
	
	// ����.

private:
	// ��������� Ÿ�� �����͸� �˻��ϴ� �Լ�.
	bool SearchNodeRecursive(Node<T>* node, const T& data)
	{
		// �˻� ����.
		if (node == nullptr)
		{
			return false;
		}

		// �˻� ����.
		if (node->data == data)
		{
			return true;
		}

		// ������ ��������, ũ�� ���������� �˻�.
		if (node->data > data)
		{
			return SearchNodeRecursive(node->left, data);
		}
		else
		{
			return SearchNodeRecursive(node->right, data);
		}
	}

	// node : ���� ���ϴ� ���.
	// parent : node�� �θ� ���.
	// newData : �����Ϸ��� ������.
	Node<T>* InsertNodeRecursive(Node<T>* node, Node<T>* parent, const T& newData)
	{
		// node�� null�̸� �߰�.
		if (node == nullptr)
		{
			return new Node<T>(newData, parent);
		}

		// ���� ���.
		if (node->data > newData)
		{
			node->left = InsertNodeRecursive(node->left, node, newData);
		}

		// ū ���.
		else
		{
			node->right = InsertNodeRecursive(node->right, node, newData);
		}

		return node;
	}

private:
	// ��Ʈ ���.
	Node<T>* root;

};