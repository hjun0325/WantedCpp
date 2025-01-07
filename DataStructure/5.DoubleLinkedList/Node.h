#pragma once

#include <iostream>

// ��ũ�� ����Ʈ�� ����� ��� Ŭ����.
template<typename T>
class Node
{
	// std::cout�� ���� ����� �� �ֵ��� �����ε�.
	//friend std::ostream& operator<<(std::ostream& os, const Node& node);

	// ����.
	template<typename T>
	friend class LinkedList;

public:
	// ������.
	Node()
		: data()
	{

	}
	Node(T data)
		: data(data)
	{

	}

private:
	// ������ �ʵ�.
	T data;

	// ��ũ �ʵ�.
	Node<T>* next = nullptr;
	Node<T>* previous = nullptr;
};