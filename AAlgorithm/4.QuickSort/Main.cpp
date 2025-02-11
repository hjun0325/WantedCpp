#include <iostream>
#include <Windows.h>

// 피벗(Pivot) 선택 함수.
int Partition(int* array, int left, int right)
{
	// 피벗 선택.
	int first = left;
	int pivot = array[first];

	// 다음 위치로 이동.
	++left;

	// 두 인덱스가 서로 교차할 때까지 진행.
	while (left <= right)
	{
		// left는 pivot보다 큰 값 선택.
		while (array[left] <= pivot)
		{
			++left;
		}

		// right는 pivot보다 작은 값 선택.
		while (array[right] > pivot)
		{
			--right;
		}

		// 서로 교차하지 않았을 때만 값 교환.
		if (left >= right)
		{
			break;
		}

		std::swap(array[left], array[right]);
	}

	// 교환.
	std::swap(array[first], array[right]);

	// 피벗 반환.
	return right;
}

// 퀵 정렬 함수.
void QuickSort(int* array, int left, int right)
{
	// 탈출 조건,
	if (left >= right)
	{
		return;
	}

	// 분할.
	int partition = Partition(array, left, right);

	// 왼쪽 배열 퀵 정렬.
	QuickSort(array, left, partition - 1);
	 
	// 오른쪽 배열 퀵 정렬.
	QuickSort(array, partition + 1, right);
}

// 배열 출력 함수.
void PrintArray(int* array, int length)
{
	for (int ix = 0;ix < length;++ix)
	{
		std::cout << array[ix] << (ix < length - 1 ? ", " : " ");
	}

	std::cout << "\n";
}

// 메인 함수(진입점).
int main()
{
	// 자료 집합
	int array[] = { 18, 19, 21, 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16, 11, 25 };

	// 배열 길이.
	int length = _countof(array);

	// 정렬 전 출력.
	std::cout << "정렬 전: ";
	PrintArray(array, length);

	// 정렬.
	QuickSort(array, 0, length-1);

	// 정렬 후 출력.
	std::cout << "정렬 후: ";
	PrintArray(array, length);


	std::cin.get();
}