#include <iostream>

// 다 값을 서로 교환하는 함수.
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// 버블 정렬 함수.
void BubbleSort(int* array, int length)
{
	// 정렬.
	for (int ix = 0;ix < length - 1;++ix)
	{
		for (int jx = 0;jx < length - 1 - ix;++jx)
		{
			// 두개씩 비교.
			if (array[jx] > array[jx + 1])
			{
				// 교환.
				Swap(array[jx], array[jx + 1]);
			}
		}
	}
}

// 출력 함수.
void PrintArray(int* array, int length)
{
	for (int ix = 0;ix < length;++ix)
	{
		std::cout << array[ix] << " ";
	}

	std::cout << "\n";
}

int main()
{
	// 자료 집합.
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	// 배열의 길이.
	int length = sizeof(array) / sizeof(array[0]);

	// 출력.
	std::cout << "정렬 전: ";
	PrintArray(array, length);

	// 정렬.
	BubbleSort(array, length);

	// 출력.
	std::cout << "정렬 후: ";
	PrintArray(array, length);

	std::cin.get();
}