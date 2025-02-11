#include <iostream>
#include <Windows.h>

// �ǹ�(Pivot) ���� �Լ�.
int Partition(int* array, int left, int right)
{
	// �ǹ� ����.
	int first = left;
	int pivot = array[first];

	// ���� ��ġ�� �̵�.
	++left;

	// �� �ε����� ���� ������ ������ ����.
	while (left <= right)
	{
		// left�� pivot���� ū �� ����.
		while (array[left] <= pivot)
		{
			++left;
		}

		// right�� pivot���� ���� �� ����.
		while (array[right] > pivot)
		{
			--right;
		}

		// ���� �������� �ʾ��� ���� �� ��ȯ.
		if (left >= right)
		{
			break;
		}

		std::swap(array[left], array[right]);
	}

	// ��ȯ.
	std::swap(array[first], array[right]);

	// �ǹ� ��ȯ.
	return right;
}

// �� ���� �Լ�.
void QuickSort(int* array, int left, int right)
{
	// Ż�� ����,
	if (left >= right)
	{
		return;
	}

	// ����.
	int partition = Partition(array, left, right);

	// ���� �迭 �� ����.
	QuickSort(array, left, partition - 1);
	 
	// ������ �迭 �� ����.
	QuickSort(array, partition + 1, right);
}

// �迭 ��� �Լ�.
void PrintArray(int* array, int length)
{
	for (int ix = 0;ix < length;++ix)
	{
		std::cout << array[ix] << (ix < length - 1 ? ", " : " ");
	}

	std::cout << "\n";
}

// ���� �Լ�(������).
int main()
{
	// �ڷ� ����
	int array[] = { 18, 19, 21, 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16, 11, 25 };

	// �迭 ����.
	int length = _countof(array);

	// ���� �� ���.
	std::cout << "���� ��: ";
	PrintArray(array, length);

	// ����.
	QuickSort(array, 0, length-1);

	// ���� �� ���.
	std::cout << "���� ��: ";
	PrintArray(array, length);


	std::cin.get();
}