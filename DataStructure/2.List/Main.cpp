#include <iostream>
#include <vector> //���� �迭

// ���� ���̺귯��.
// Vector2 / Vector3 / Vector4.

// �ݺ���(Iterator) Ŭ����/
template<typename List>
class VectorIterator
{
public:
	//Ÿ�� ����
	using ValueType = typename List::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;

public:
	VectorIterator(PointerType pointer)
		: pointer(pointer)
	{

	}

	//������ ���� ���� ������ �����ε�.
	VectorIterator& operator++()
	{
		++pointer;
		return *this;
	}

	//������ ���� ���� ������ �����ε�.
	VectorIterator& operator++(int)
	{
		VectorIterator iterator = *this;
		++(*this);
		return iterator;
	}

	//������ ���� ���� ������ �����ε�.
	VectorIterator& operator--()
	{
		--pointer;
		return *this;
	}

	//������ ���� ���� ������ �����ε�.
	VectorIterator& operator--(int)
	{
		VectorIterator iterator = *this;
		--(*this);
		return iterator;
	}

	// �ε��� ������ �����ε�
	ReferenceType operator[](int index)
	{
		return *(pointer + index);
	}

	// ������ ������ �����ε�
	PointerType operator->()
	{
		return pointer;
	}

	//�� ��ȯ ������
	ReferenceType operator*()
	{
		return *pointer;
	}

	//�� ������
	bool operator==(const VectorIterator& other) const
	{
		return (pointer == other.pointer);
	}
	bool operator!=(const VectorIterator& other) const
	{
		return (pointer != other.pointer);
		//return !(*this == other);
	}

private:
	PointerType pointer;
};

// ���� �迭(����Ʈ) Ŭ����.
// ���ø�.
template<typename T>
class List
{
public:
	using ValueType = T;
	using Iterator = VectorIterator<List<T>>;

public:
	List()
	{
		// �ʱ� ������ ���� ����.
		data = new T[capacity];
	}

	~List()
	{
		// �����Ͱ� ����Ű�� �� �迭 ���� ����.
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}

	// ���� �߰�.
	void Pushback(const T& value)
	{
		// �ڷḦ �߰��� �� �ִ� ����� ������ �ִ��� Ȯ��.
		if (count == capacity)
		{
			ReAllocate(capacity * 2);
		}

		// ���� �迭�� ������ ��ҿ� ���޹��� ������ ����.
		data[count] = value;
		// ����� ����� �� ���� ó��.
		++count;
	}

	// Move �߰�.
	void Pushback(T&& value)
	{
		// �ڷḦ �߰��� �� �ִ� ����� ������ �ִ��� Ȯ��.
		if (count == capacity)
		{
			ReAllocate(capacity * 2);
		}

		// ���� �迭�� ������ ��ҿ� ���޹��� ������ ����.
		data[count] = std::move(value);
		// ����� ����� �� ���� ó��.
		++count;
	}

	// ���� �Լ�.
	T& At(int index)
	{
		// ���� ó��
		if (index >= count)
		{
			__debugbreak();
		}

		return data[index];
	}

	// ���� �Լ�.
	const T& At(int index) const
	{
		// ���� ó��
		if (index >= count)
		{
			__debugbreak();
		}

		return data[index];
	}

	// ������ �����ε�
	T& operator[](int index)
	{
		// ���� ó��
		if (index >= count)
		{
			__debugbreak();
		}

		return data[index];
	}

	// ������ �����ε�
	const T& operator[](int index) const
	{
		// ���� ó��
		if (index >= count)
		{
			__debugbreak();
		}

		return data[index];
	}

	//Iterator ���� �Լ�
	Iterator begin()
	{
		return Iterator(data);
	}

	Iterator end()
	{
		return Iterator(data + count);
	}

	// Getter.
	// ��� �� ��ȯ.
	int Count() const { return count; }

	// ���� �뷮 ��ȯ.
	int Capacity() const { return capacity; }

	// �迭 �ּ� ��ȯ.
	T* Data() const { return data; }

private:
	// ������ ������ ������ �� ������ �ø��� �Լ�.
	void ReAllocate(int newCapactiy)
	{
		// 1. ���ο� �޸� ���� �Ҵ�(Allocate).
		// 2. ������ ������ ����.
		// 3. ���� ������ �� �ӽ� ������ ����
		T* newBlock = new T[newCapactiy];
		memset(newBlock, 0, sizeof(T) * newCapactiy);

		//// ����.
		//for (int ix = 0; ix < count; ++ix)
		//{
		//	//newBlock[ix] = data[ix]; // 1
		//	newBlock[ix] = std::move(data[ix]); // 2
		//}

		// �޸� ����
		memcpy(newBlock, data, sizeof(T) * count); // 3

		delete[] data;
		data = newBlock;
		capacity = newCapactiy;
	}

private:
	// ������ ���� (���� �Ҵ��� �迭 ����).
	T* data = nullptr;

	// �뷮
	int capacity = 2;

	// �迭 ������ ��
	int count = 0;
};

int main()
{
	// ���� �迭 ��ü ����
	List<int> list;

	List<int>::ValueType;

	// ���� �߰�
	for (int ix = 0;ix < 100;++ix)
	{
		list.Pushback(ix); //ix,����� ���� �ٸ� �����ε�
	}

	char buffer[256];
	snprintf(buffer, 256, "%d, %d\n", list.Count(), list.Capacity());

	//const int& value = list[100];
	std::cout << buffer;
	std::cout << list.Count() << ", " << list.Capacity() << "\n";

	//Configuration(����)
	//	- Debug : ����� ���.����.����� ȯ�� �� ���� �߰� ����.
	//	- __debugbreak()�� Release��忡�� �������� ����? �ƴҼ���
	//	- Release : ��� ���.����.�ڵ� ����ȭ.�޸� ������ ����.

	// Standard Template Library(STL) ���� �迭
	std::vector<int> vector;
	/*{
		1,2,3,4,5
	};*/

	for (int ix = 0;ix < 100;++ix)
	{
		vector.push_back(ix);
		//vector.emplace_back(10);
	}

	//�б�
	//Range-Based Loop / Ranged Loop.
	//for (const auto& item : vector) //���� ������� ������ Ȯ���� �� ����
	//{
	//	std::cout << item << " ";
	//}

	for (const auto& item : list)
	{
		std::cout << item << " ";
	}

	for (List<int>::Iterator iterator = list.begin();iterator != list.end();++iterator)
	{
		std::cout << *iterator << " ";
	}

	std::cout << "\n";

	snprintf(buffer, 256, "%d, %d",
		static_cast<int>(vector.size()),
		static_cast<int>(vector.capacity()));

	std::cout << buffer;
}