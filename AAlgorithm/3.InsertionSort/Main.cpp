#include <iostream>

// ���� ���� �Լ�.
void InsertionSort(int* array, int length)
{
	// �迭 ��ȸ.
	for (int ix = 0;ix < length;++ix)
	{
		// Ű �̱�.
		int keyValue = array[ix];
		int jx = ix - 1;

		// ���ø�(��ȯ).
		while (jx >= 0 && array[jx] > keyValue)
		{
			array[jx + 1] = array[jx];
			--jx;
		}

		// �� �����.
		array[jx + 1] = keyValue;
	}
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

int main()
{
	// �ڷ� ����
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	// �迭 ����.
	int length = sizeof(array) / sizeof(array[0]);

	// ���� �� ���.
	std::cout << "���� ��: ";
	PrintArray(array, length);

	// ����.
	InsertionSort(array, length);

	// ���� �� ���.
	std::cout << "���� ��: ";
	PrintArray(array, length);

	std::cin.get();
}