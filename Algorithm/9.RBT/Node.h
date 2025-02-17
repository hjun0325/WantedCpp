#pragma once

#include <iostream>
#include <string>

// �޸� ���� �Լ�.
template<typename T>
void SafeDelete(T*& t)
{
	if (t)
	{
		delete t;
		t = nullptr;
	}
}

// ��� ���� ������.
enum class Color
{
	Red,
	Black
};

// ��� Ŭ����.
class Node
{
public:
	// ������.
	Node(int data = 0, Color color = Color::Red);
	~Node() = default;

	// Getter/Setter.
	inline const int Data() const { return data; }
	inline void SetData(int newData) { data = newData; }

	inline const Color GetColor() const { return color; }
	inline void SetColor(Color newColor) { color = newColor; }
	const char* ColorString() const;

	inline Node* Parent() const { return parent; }
	inline void SetParent(Node* newParent) { parent = newParent; }

	inline Node* Left() const { return left; }
	inline void SetLeft(Node* newLeft) { left = newLeft; }

	inline Node* Right() const { return right; }
	inline void SetRight(Node* newRight) { right = newRight; }

private:
	// ������.
	int data = 0;

	// ����.
	Color color = Color::Red;

	// �θ� ���.
	Node* parent = nullptr;

	// ���� �ڽ� ���.
	Node* left = nullptr;
	
	// ������ �ڽ� ���.
	Node* right = nullptr;
};