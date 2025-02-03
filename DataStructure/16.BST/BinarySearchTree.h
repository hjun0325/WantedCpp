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
		Destroy();
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
	void DeleteNode(const T& deleteData)
	{
		// ��������� �����ϴ� �Լ��� ȣ��.
		// ���� ������ ������ Root ���.
		// ���� ó���� �ȵ� �ڵ�.
		root = DeleteNodeRecursive(root, deleteData);
	}

	// �ּҰ� �˻� �Լ�.
	// node: �˻��� �����ϴ� ���.
	Node<T>* SearchMinValue(Node<T>* node)
	{
		// �˻� ����.
		// ���� ���� Ʈ���� ����ؼ� �̵��ϸ鼭, �ּ� �� �˻�.
		while (node->left != nullptr)
		{
			// ���� ���� ���� �̵�.
			node = node->left;
		}

		// �ּ� ���� ���� ��带 ��ȯ.
		return node;
	}

	// ��� (���� ��ȸ).
	void PreorderTraverse(int depth = 0)
	{
		std::cout << "========== ���� ��ȸ ���� ==========\n";

		// ����� ���� ���� ��ȸ ������� ��� �Լ��� ȣ��.
		// Ž�� ������ ��Ʈ ��Ʈ���� ����.
		PreorderTraverseRecursive(root, depth);

		std::cout << "========== ���� ��ȸ ���� ==========\n";
	}

	// ��� (���� ��ȸ).
	void InorderTraverse(int depth = 0)
	{
		std::cout << "========== ���� ��ȸ ���� ==========\n";

		// ����� ���� ���� ��ȸ ������� ��� �Լ��� ȣ��.
		// Ž�� ������ ��Ʈ ��Ʈ���� ����.
		InorderTraverseRecursive(root, depth);

		std::cout << "========== ���� ��ȸ ���� ==========\n";
	}

	// ��� (���� ��ȸ).
	void PostorderTraverse(int depth = 0)
	{
		std::cout << "========== ���� ��ȸ ���� ==========\n";

		// ����� ���� ���� ��ȸ ������� ��� �Լ��� ȣ��.
		// Ž�� ������ ��Ʈ ��Ʈ���� ����.
		PostorderTraverseRecursive(root, depth);

		std::cout << "========== ���� ��ȸ ���� ==========\n";
	}

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

	// ���� ��� �Լ�.
	Node<T>* DeleteNodeRecursive(Node<T>* node, const T& deleteData)
	{
		// ���� ����.
		// ��尡 null�̸� ������ ��带 ã�� ���� ���̱� ������ null�� ��ȯ�ϰ� ����.
		if (node == nullptr)
		{
			return nullptr;
		}

		// �����Ϸ��� �����Ͱ� �� �����ͺ��� ������ ���� ���� Ʈ���� �̵�.
		if (node->data > deleteData)
		{
			node->left = DeleteNodeRecursive(node->left, deleteData);
		}
		
		// �����Ϸ��� �����Ͱ� �� �����ͺ��� ũ�� ������ ���� Ʈ���� �̵�.
		else if (node->data < deleteData)
		{
			node->right = DeleteNodeRecursive(node->right, deleteData);
		}

		// ã����, ���� ó��.
		else
		{
			// ��� 1 - �ڽ��� ���� ���. (�� ��� null�� ���)
			if (node->left == nullptr && node->right == nullptr)
			{
				// ��� ���� �� �Լ� ����.
				delete node;
				return nullptr;
			}
			
			// ��� 3 - �ڽ��� �� �� �ִ� ���.(�� ��ΰ� null�� �ƴ� ���).
			if (node->left != nullptr && node->right != nullptr)
			{
				// �����Ǵ� ����� ������ ���� Ʈ������ ���� ���� ���� �˻��ؼ� �����ϴ� ����� ���� ������Ʈ.
				node->data = SearchMinValue(node->right)->data;

				// ������ ���� ������ ���� Ʈ������ ���� ���� ���� ���� ��带 ����.
				node->right = DeleteNodeRecursive(node->right, node->data);
			}

			// ��� 2 - �ڽ��� �ϳ��� �ִ� ��� (�� �� �ϳ��� null�� ���).
			else
			{
				// ���� �ڽĸ� �ִ� ���.
				if (node->left != nullptr)
				{
					// �ӽ� ����.
					Node<T>* left = node->left;

					// ����.
					delete node;

					// ���� �ڼ� ��ȯ.
					return left;
				}

				// ������ �ڽĸ� �ִ� ���.
				else if (node->right != nullptr)
				{
					// �ӽ� ����.
					Node<T>* right = node->right;

					// ����.
					delete node;

					// ������ �ڼ� ��ȯ.
					return right;
				}
			}
		}
		
		return node;
	}

	// ���� ��ȸ ��� �Լ�.
	void PreorderTraverseRecursive(Node<T>* node, int depth = 0)
	{
		// ���� ����.
		if (node == nullptr)
		{
			// Ʈ�� ��带 ����� �� ������ �����ֱ� ���� �� ���� ���.
			for (int ix = 0; ix < depth;++ix)
			{
				std::cout << "  ";
			}

			std::cout << "null\n";
			return;
		}

		// Ʈ�� ��带 ����� �� ������ �����ֱ� ���� �� ���� ���.
		for (int ix = 0;ix < depth;++ix)
		{
			std::cout << "  ";
		}

		// �θ� ��� ó��.
		std::cout << node->data << "\n";

		// ���� ���� Ʈ���� ���� ��ȸ.
		PreorderTraverseRecursive(node->left, depth + 1);

		// ������ ���� Ʈ���� ���� ��ȸ.
		PreorderTraverseRecursive(node->right, depth + 1);
	}

	// ���� ��ȸ ��� �Լ�.
	void InorderTraverseRecursive(Node<T>* node, int depth = 0)
	{
		// ���� ����.
		if (node == nullptr)
		{
			// Ʈ�� ��带 ����� �� ������ �����ֱ� ���� �� ���� ���.
			for (int ix = 0; ix < depth; ++ix)
			{
				std::cout << "  ";
			}

			std::cout << "null\n";
			return;
		}

		// ���� ���� Ʈ���� ���� ��ȸ.
		InorderTraverseRecursive(node->left, depth + 1);

		// Ʈ�� ��带 ����� �� ������ �����ֱ� ���� �� ���� ���.
		for (int ix = 0; ix < depth; ++ix)
		{
			std::cout << "  ";
		}

		// �θ� ��� ó��.
		std::cout << node->data << "\n";

		// ������ ���� Ʈ���� ���� ��ȸ.
		InorderTraverseRecursive(node->right, depth + 1);
	}

	// ���� ��ȸ ��� �Լ�.
	void PostorderTraverseRecursive(Node<T>* node, int depth = 0)
	{
		// ���� ����.
		if (node == nullptr)
		{
			// Ʈ�� ��带 ����� �� ������ �����ֱ� ���� �� ���� ���.
			for (int ix = 0; ix < depth; ++ix)
			{
				std::cout << "  ";
			}

			std::cout << "null\n";
			return;
		}

		// ���� ���� Ʈ���� ���� ��ȸ.
		PostorderTraverseRecursive(node->left, depth + 1);

		// ������ ���� Ʈ���� ���� ��ȸ.
		PostorderTraverseRecursive(node->right, depth + 1);

		// Ʈ�� ��带 ����� �� ������ �����ֱ� ���� �� ���� ���.
		for (int ix = 0; ix < depth; ++ix)
		{
			std::cout << "  ";
		}

		// �θ� ��� ó��.
		std::cout << node->data << "\n";
	}

	// ��� ��带 ������ �� ����ϴ� �Լ�.
	void Destroy()
	{
		// ��Ʈ ��尡 null�̸� ����.
		if (root == nullptr)
		{
			return;
		}

		// ���� �ڼ� > ������ �ڼ� > ��Ʈ ������ ����.
		DestroyRecursive(root);
	}

	void DestroyRecursive(Node<T>* node)
	{
		// ����Լ� ���� ����.
		if (node == nullptr)
		{
			return;
		}

		// ���� �ڼ� / ������ �ڼ� Ȯ��.
		Node<T>* left = node->left;
		Node<T>* right = node->right;

		// �ڼ��� ���� ���.
		if (left == nullptr && right == nullptr)
		{
			// ��� ���� �� �Լ� ����.
			delete node;
			return;
		}

		DestroyRecursive(left);
		DestroyRecursive(right);

		delete node;
	}

private:
	// ��Ʈ ���.
	Node<T>* root;

};