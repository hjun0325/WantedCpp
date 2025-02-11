#include <iostream>
#include <vector>

// �� ����� (Heapify).
void Heapify(std::vector<int>& array, int length, int ix)
{
	while (true)
	{
		// �� ������ ���� �ε��� ����.
		int largestIdx = ix;

		// ���� �ڼ� �ε���.
		int leftIdx = 2 * ix + 1;

		// ������ �ڼ� �ε���.
		int rightIdx = 2 * ix + 2;

		if (leftIdx < length && array[leftIdx] > array[largestIdx])
		{
			largestIdx = leftIdx;
		}

		if (rightIdx < length && array[rightIdx] > array[largestIdx])
		{
			largestIdx = rightIdx;
		}

		if (largestIdx == ix)
		{
			break;
		}
		
		std::swap(array[ix], array[largestIdx]);
		ix = largestIdx;
	}
}

// �� ���� �Լ� (HeapSort).
void HeapSort(std::vector<int>& array)
{
	// ��ü ũ��.
	int length = (int)array.size();
	
	// �� ����.
	for (int ix = length / 2 - 1;ix >= 0;--ix)
	{
		// �� �����.
		Heapify(array, length, ix);
	}

	// ����.
	for (int ix = length - 1;ix > 0;--ix)
	{
		std::swap(array[0], array[ix]);
		Heapify(array, ix, 0);
	}
}

// �迭 ��� �Լ�.
void PrintArray(std::vector<int>& array)
{
	for (int ix = 0; ix < (int)array.size(); ++ix)
	{
		std::cout << array[ix] << (ix < (int)array.size() - 1 ? ", " : "");
	}

	std::cout << "\n";
}

int main()
{
	// �迭.
	std::vector<int> array = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	// ���� �� ���.
	std::cout << "���� ��: ";
	PrintArray(array);

	// ����.
	HeapSort(array);

	// ���� �� ���.
	std::cout << "���� ��: ";
	PrintArray(array);
}