#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	int* arr = new int[n];
	int maxValue = -1000;
	for (int ix = 0;ix < n;++ix)
	{
		std::cin >> arr[ix];
		if (ix != 0)
		{
			if (arr[ix] < arr[ix - 1] + arr[ix])
			{
				arr[ix] = arr[ix - 1] + arr[ix];
				if (maxValue < arr[ix])
				{
					maxValue = arr[ix];
				}
			}
			else
			{
				if (maxValue < arr[ix])
				{
					maxValue = arr[ix];
				}
			}
		}
		else {
			maxValue = arr[ix];
		}
	}
	std::cout << maxValue;
}