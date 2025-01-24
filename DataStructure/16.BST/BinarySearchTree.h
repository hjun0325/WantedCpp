#pragma once

#include "Node.h"

// 이진 탐색 트리 클래스.
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
		// 재귀 삭제 함수 호출.
	}

	// 검색.
	// (공개) 메소드(Method)/함수 - 메시지 (인터페이스/프로토콜).
	// 공개 / 감출지.
	bool SearchNode(const T& data)
	{
		// 루트부터 재귀적으로 검색.
		return SearchNodeRecursive(root, data);
	}
	
	// 삽입.
	// 규칙->
	// 0. 중복 허용하지 않음.
	// 1. 시작->루트에서부터 비교 시작.
	// 1-1. 루트가 비어 있으면 새 노드를 루트로 지정.
	// 2. 새로 추가하는 값이 비교 노드보다 작으면 왼쪽 하위 트리로 비교를 이어간다.
	// 3. 새로 추가하는 값이 비교 노드보다 크면 오른쪽 하위 트리로 비교를 이어간다.
	bool InsertNode(const T& newData)
	{
		// 중복을 허용하지 않기 때문에 이미 있으면 실패.
		if (SearchNode(newData))
		{
			// 오류 메시지 출력.
			std::cout << "Error: 이미 중복된 값이 있어 추가 불가능\n";
			return false;
		}

		// case1. 루트가 null.
		if (root == nullptr)
		{
			// 루트 생성 후 성공.
			root = new Node<T>(newData, nullptr);
			return true;
		}

		// case2/3. 재귀 함수로 처리.
		root = InsertNodeRecursive(root, nullptr, newData);
		return true;
	}
	
	// 삭제.

private:
	// 재귀적으로 타겟 데이터를 검색하는 함수.
	bool SearchNodeRecursive(Node<T>* node, const T& data)
	{
		// 검색 실패.
		if (node == nullptr)
		{
			return false;
		}

		// 검색 성공.
		if (node->data == data)
		{
			return true;
		}

		// 작으면 왼쪽으로, 크면 오른쪽으로 검색.
		if (node->data > data)
		{
			return SearchNodeRecursive(node->left, data);
		}
		else
		{
			return SearchNodeRecursive(node->right, data);
		}
	}

	// node : 현재 비교하는 노드.
	// parent : node의 부모 노드.
	// newData : 삽입하려는 데이터.
	Node<T>* InsertNodeRecursive(Node<T>* node, Node<T>* parent, const T& newData)
	{
		// node가 null이면 추가.
		if (node == nullptr)
		{
			return new Node<T>(newData, parent);
		}

		// 작은 경우.
		if (node->data > newData)
		{
			node->left = InsertNodeRecursive(node->left, node, newData);
		}

		// 큰 경우.
		else
		{
			node->right = InsertNodeRecursive(node->right, node, newData);
		}

		return node;
	}

private:
	// 루트 노드.
	Node<T>* root;

};