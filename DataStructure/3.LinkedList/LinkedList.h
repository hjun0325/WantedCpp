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
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	// ��忡 �߰��ϴ� �Լ�.
	void AddToHead(int data);

	// �� �ڿ� �����ϴ� �Լ�.
	void Insert(int data);

	// �����͸� ������ �˻� �� �����ϴ� �Լ�.
	void Delete(int data);

	// ����� ��� ��� �Լ�.
	void Print();

	// ����� ����� �� ��ȯ �Լ�(Getter).
	/*__forceinline*/ inline int Count() const;

private:
	// ���(����) ���.
	Node* head = nullptr;

	// ����� �ڷ� ���� ��Ÿ���� ����.
	int count = 0;
};