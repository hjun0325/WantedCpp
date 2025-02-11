#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// ���� �Լ� (Merge).
// array: ������ �迭 ����.
// leftArray: ���� �迭.
// leftArrayLength: ���� �迭 ũ��.
// rightArray: ������ �迭.
// rightArrayLength: ������ �迭 ũ��.
void Merge(int* array,
	int* leftArray, int leftArrayLength,
	int* rightArray, int rightArrayLength)
{
	// �ε��� ���� ����.
	int leftIndex = 0;
	int rightIndex = 0;
	int mergeIndex = 0;

	// ����/������ �迭�� ��Ҹ� ���ϸ鼭 ���� ������ array�� �� �Ҵ�.
	while (leftIndex < leftArrayLength && rightIndex < rightArrayLength)
	{
		// ����/������ ��.
		if (leftArray[leftIndex] <= rightArray[rightIndex])
		{
			array[mergeIndex] = leftArray[leftIndex];
			++leftIndex;
		}
		else
		{
			array[mergeIndex] = rightArray[rightIndex];
			++rightIndex;
		}

		++mergeIndex;
	}

	// �� �������� ���� ���� �迭 ��Ҹ� ���� �迭�� ����.
	while (leftIndex < leftArrayLength)
	{
		array[mergeIndex] = leftArray[leftIndex];
		++mergeIndex;
		++leftIndex;
	}

	// �� �������� ���� ������ �迭 ��Ҹ� ���� �迭�� ����.
	while (rightIndex < rightArrayLength)
	{
		array[mergeIndex] = rightArray[rightIndex];
		++mergeIndex;
		++rightIndex;
	}
}

// ���� �Լ� (MergeSort).
void MergeSort(int* array, int length)
{
	// Ż�� ����.
	if (length <= 1)
	{
		return;
	}

	// �迭 ����(������).
	int mid = length / 2;
	
	// ����/������ �迭�� ���� Ȯ��.
	int* leftArray = new int[mid];
	int* rightArray = new int[length - mid];

	// �� ����.
	// �迭�� �̸��� �ּ�(��, ������).
	// �޸� ������ ��ŭ ��.
	memcpy(leftArray, array, sizeof(int) * mid);
	memcpy(rightArray, array + mid, sizeof(int) * (length - mid));

	// ����� ȣ��.
	// ���� �迭�� ���� ��� ȣ��.
	MergeSort(leftArray, mid);

	// ������ �迭�� ���� ��� ȣ��.
	MergeSort(rightArray, length - mid);

	// ����.
	Merge(array, leftArray, mid, rightArray, length - mid);

	// �޸� ����.
	delete[] leftArray;
	delete[] rightArray;
}

// �迭 ��� �Լ�.
void PrintArray(int array[], int length)
{
	for (int ix = 0; ix < length; ++ix)
	{
		std::cout << array[ix] << (ix < length - 1 ? ", " : "");
	}

	std::cout << "\n";
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// �迭.
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	// ���� ���.
	int length = _countof(array);

	// ���� �� ���.
	std::cout << "���� ��: ";
	PrintArray(array, length);

	// ����.
	MergeSort(array, length);

	// ���� �� ���.
	std::cout << "���� ��: ";
	PrintArray(array, length);

	std::cin.get();
}