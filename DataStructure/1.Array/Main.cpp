#include <iostream>
#include <array>

template<typename T, size_t size>
class Array
{
public:
	T& operator[](int index)
	{
		//���� ó��

		return data[index];
	}

	size_t Count() const { return size; }
private:
	T data[size];
};

void Function(Array<int, 10>& array)
{

}

int main()
{
	//ũ�Ⱑ 10�� ���� int�� �迭
	int array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	//�� �迭
	int* heapArray = new int[10] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//����
	delete[] heapArray;

	//�迭 ��ü
	Array<int, 10> arrayobject;
	arrayobject[0] = 10;
	arrayobject[1] = 20;
	arrayobject[2] = 30;

	std::cout << arrayobject.Count() << "\n";

	//STL array
	std::array<int, 10> stlArray;
	stlArray[0] = 100;
	stlArray[1] = 200;
	stlArray[2] = 300;

	size_t arraySize = stlArray.size();
}