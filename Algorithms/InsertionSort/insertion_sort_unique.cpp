#include "insertion_sort_unique.h"

void insertion_sort_unique(std::unique_ptr<int[]>& arr, size_t& length)
{
	for (int i = 1; i < length; ++i)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void input_data_unique(std::unique_ptr<int[]>& arr, size_t& length)
{
	for (int i = 0; i < length; ++i)
	{
		std::cin >> arr[i];
	}
}

void output_unique(std::unique_ptr<int[]>& arr, size_t& length)
{
	for (int i = 0; i < length; ++i)
	{
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
	}
}
