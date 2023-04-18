#include <iostream>
#include "insertion_sort.h"

void input_data(int*& arr, size_t& length)
{
	for (int i = 0; i < length; ++i)
	{
		std::cin >> *(arr + i);
	}
}

void output(int*& arr, size_t& length)
{
	for (int i = 0; i < length; ++i)
	{
		std::cout << "arr[" << i << "] = " << *(arr + i) << std::endl;
	}
}

void insertion_sort(int*& arr, size_t& length)
{
	for (int j = 1; j < length; ++j)
	{
		int i = j - 1;
		int key = arr[j];
		while (i >= 0 && arr[i] > key)
		{
			arr[i + 1] = arr[i];
			--i;
		}
		arr[i + 1] = key;
	}
}
