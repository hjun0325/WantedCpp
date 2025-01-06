#include <iostream>
#include <vector> //동적 배열

// 수학 라이브러리.
// Vector2 / Vector3 / Vector4.

// 반복자(Iterator) 클래스/
template<typename List>
class VectorIterator
{
public:
	//타입 지정
	using ValueType = typename List::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;

public:
	VectorIterator(PointerType pointer)
		: pointer(pointer)
	{

	}

	//포인터 전위 증가 연산자 오버로딩.
	VectorIterator& operator++()
	{
		++pointer;
		return *this;
	}

	//포인터 후위 증가 연산자 오버로딩.
	VectorIterator& operator++(int)
	{
		VectorIterator iterator = *this;
		++(*this);
		return iterator;
	}

	//포인터 전위 감소 연산자 오버로딩.
	VectorIterator& operator--()
	{
		--pointer;
		return *this;
	}

	//포인터 후위 감소 연산자 오버로딩.
	VectorIterator& operator--(int)
	{
		VectorIterator iterator = *this;
		--(*this);
		return iterator;
	}

	// 인덱스 연산자 오버로딩
	ReferenceType operator[](int index)
	{
		return *(pointer + index);
	}

	// 포인터 연산자 오버로딩
	PointerType operator->()
	{
		return pointer;
	}

	//값 반환 연산자
	ReferenceType operator*()
	{
		return *pointer;
	}

	//비교 연산자
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

// 동적 배열(리스트) 클래스.
// 템플릿.
template<typename T>
class List
{
public:
	using ValueType = T;
	using Iterator = VectorIterator<List<T>>;

public:
	List()
	{
		// 초기 데이터 공간 설정.
		data = new T[capacity];
	}

	~List()
	{
		// 포인터가 가리키는 힙 배열 변수 삭제.
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}

	// 원소 추가.
	void Pushback(const T& value)
	{
		// 자료를 추가할 수 있는 충분한 공간이 있는지 확인.
		if (count == capacity)
		{
			ReAllocate(capacity * 2);
		}

		// 현재 배열의 마지막 요소에 전달받은 데이터 설정.
		data[count] = value;
		// 저장된 요소의 수 증가 처리.
		++count;
	}

	// Move 추가.
	void Pushback(T&& value)
	{
		// 자료를 추가할 수 있는 충분한 공간이 있는지 확인.
		if (count == capacity)
		{
			ReAllocate(capacity * 2);
		}

		// 현재 배열의 마지막 요소에 전달받은 데이터 설정.
		data[count] = std::move(value);
		// 저장된 요소의 수 증가 처리.
		++count;
	}

	// 접근 함수.
	T& At(int index)
	{
		// 예외 처리
		if (index >= count)
		{
			__debugbreak();
		}

		return data[index];
	}

	// 접근 함수.
	const T& At(int index) const
	{
		// 예외 처리
		if (index >= count)
		{
			__debugbreak();
		}

		return data[index];
	}

	// 연산자 오버로딩
	T& operator[](int index)
	{
		// 예외 처리
		if (index >= count)
		{
			__debugbreak();
		}

		return data[index];
	}

	// 연산자 오버로딩
	const T& operator[](int index) const
	{
		// 예외 처리
		if (index >= count)
		{
			__debugbreak();
		}

		return data[index];
	}

	//Iterator 관련 함수
	Iterator begin()
	{
		return Iterator(data);
	}

	Iterator end()
	{
		return Iterator(data + count);
	}

	// Getter.
	// 요소 수 반환.
	int Count() const { return count; }

	// 저장 용량 반환.
	int Capacity() const { return capacity; }

	// 배열 주소 반환.
	T* Data() const { return data; }

private:
	// 저장할 공간이 부족할 때 공간을 늘리는 함수.
	void ReAllocate(int newCapactiy)
	{
		// 1. 새로운 메모리 공간 할당(Allocate).
		// 2. 기존의 데이터 복사.
		// 3. 기존 데이터 및 임시 데이터 삭제
		T* newBlock = new T[newCapactiy];
		memset(newBlock, 0, sizeof(T) * newCapactiy);

		//// 복사.
		//for (int ix = 0; ix < count; ++ix)
		//{
		//	//newBlock[ix] = data[ix]; // 1
		//	newBlock[ix] = std::move(data[ix]); // 2
		//}

		// 메모리 복사
		memcpy(newBlock, data, sizeof(T) * count); // 3

		delete[] data;
		data = newBlock;
		capacity = newCapactiy;
	}

private:
	// 데이터 선언 (힙에 할당할 배열 변수).
	T* data = nullptr;

	// 용량
	int capacity = 2;

	// 배열 원소의 수
	int count = 0;
};

int main()
{
	// 동적 배열 객체 생성
	List<int> list;

	List<int>::ValueType;

	// 원소 추가
	for (int ix = 0;ix < 100;++ix)
	{
		list.Pushback(ix); //ix,상수는 각각 다른 오버로딩
	}

	char buffer[256];
	snprintf(buffer, 256, "%d, %d\n", list.Count(), list.Capacity());

	//const int& value = list[100];
	std::cout << buffer;
	std::cout << list.Count() << ", " << list.Capacity() << "\n";

	//Configuration(구성)
	//	- Debug : 디버그 모드.느림.디버깅 환경 및 정보 추가 전달.
	//	- __debugbreak()는 Release모드에서 동작하지 않음? 아닐수도
	//	- Release : 출시 모드.빠름.코드 최적화.메모리 정보를 못봄.

	// Standard Template Library(STL) 동적 배열
	std::vector<int> vector;
	/*{
		1,2,3,4,5
	};*/

	for (int ix = 0;ix < 100;++ix)
	{
		vector.push_back(ix);
		//vector.emplace_back(10);
	}

	//읽기
	//Range-Based Loop / Ranged Loop.
	//for (const auto& item : vector) //거의 순서대로 나오나 확신할 수 없음
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