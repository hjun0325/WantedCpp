#pragma once

#include "Node.h"

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

// ��带 ����� �ڷḦ �����ϴ� ��ũ�� ����Ʈ.
template<typename T>
class LinkedList
{
public:
	LinkedList()
	{

	}
	~LinkedList()
	{
		if (first != nullptr)
		{
			Node<T>* current = first;
			Node<T>* deleteNode = nullptr;

			while (current != nullptr)
			{
				deleteNode = current;
				current = current->next;

				delete deleteNode;
			}
		}
	}

	// ��忡 �߰��ϴ� �Լ�.
	void AddToFirst(const T& data)
	{
		// �� ��� ����.
		Node<T>* newNode = new Node<T>(data);

		// #1 - ���� ��尡 ���� ���.
		if (first == nullptr)
		{
			// ��� ��带 newNode�� ����.
			first = newNode;
		}
		// #2 - ��尡 �ִ� ���.
		else {
			// �� ����� ���� ��带 ������ ��� ���� ����.
			newNode->next = first;

			// ��� ��带 �� ���� ��ü.
			first = newNode;
		}

		// ����� ��� �� ���� ó��.
		++count;
	}

	// �� �ڿ� �����ϴ� �Լ�.
	void Insert(const T& data)
	{
		// �� ��� ����.
		Node<T>* newNode = new Node<T>(data);

		// ������ ��ġ ã��.
		// #1 - ��尡 ��� �ִ� ���.
		if (first == nullptr)
		{
			// ��� ��带 newNode�� ����.
			first = newNode;
		}
		// ������ ��ġ�� �˻� �� ��� ����.
		else
		{
			// ��� ������ 2���� ����� �˻�.
			Node<T>* current = first;
			Node<T>* trail = nullptr;

			// ��ġ �˻�.
			while (current != nullptr)
			{
				// �� ��.
				if (current->data >= data)
				{
					break;
				}

				// ���� ���� �̵�.
				trail = current;
				current = current->next;
			}

			// �˻��� ����� Ȯ���ؼ� ó��.
			// �˻��� ��尡 ��� ����� ���.
			if (current == first)
			{
				newNode->next = first;
				first = newNode;
			}
			// �˻��� ��尡 �߰� ��ġ�� ���.
			else
			{
				newNode->next = current;
				trail->next = newNode;
			}
		}
		//��� �� ���� ó��.
		++count;
	}

	// �����͸� ������ �˻� �� �����ϴ� �Լ�.
	void Delete(const T& data)
	{
		// ������ ��� ã��.
		// ���� ó��.
		if (first == nullptr)
		{
			std::cout << "����Ʈ�� ����־� ������ �Ұ��� �մϴ�.\n";
			return;
		}

		// �˻� ����.
		Node<T>* current = first;
		Node<T>* trail = nullptr;

		while (current != nullptr)
		{
			// �� ��.
			if (current->data == data)
			{
				break;
			}

			// ��� �̵�.
			trail = current;
			current = current->next;
		}

		// �˻��� ��� 2����.
		// #1 ��ã�� ���.
		if (current == nullptr)
		{
			std::cout << "��: " << data << "�� ã�� ���߽��ϴ�.\n";
			return;
		}

		// #2 ã�� ���.
		if (current == first)
		{
			// ��� ��� ��ü.
			first = first->next;
		}
		else
		{
			trail->next = current->next;
		}

		// ��� ����.
		delete current;

		// ����� ����� �� ���� ó��.
		--count;
	}

	// ����� ��� ��� �Լ�.
	void Print()
	{
		Node<T>* current = first;
		while (current != nullptr)
		{
			std::cout << "Data: " << current->data << "\n";
			current = current->next;
		}
	}

	// ����� ����� �� ��ȯ �Լ�(Getter).
	/*__forceinline*/ inline int Count() const
	{
		return count;
	}

private:
	// ���(����) ���.
	Node<T>* first = nullptr;

	// ����� �ڷ� ���� ��Ÿ���� ����.
	int count = 0;
};