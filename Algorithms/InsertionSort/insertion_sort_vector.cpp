#include "insertion_sort_vector.h"

void insertion_sort_vector(std::vector<int>& arr, size_t& length)
{
	for (int i = 1; i < length; ++i)
	{
		int j = i - 1;
		int key = arr[i];
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

void input_data_vector(std::vector<int>& arr, size_t& length)
{
	for (int i = 0; i < length; ++i)
	{
		std::cin >> arr[i];
	}
}

void output_vector(std::vector<int>& arr, size_t& length)
{
	for (int i = 0; i < length; ++i)
	{
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
	}
}
