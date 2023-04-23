#include "merge_sort_vector.h"
#include <iostream>

template<typename T>
void merge_vector(std::vector<T>& arr, int left, int mid, int right)
{
	int i = left, j = mid + 1, k = 0;
	std::vector<T> tmp(right - left + 1);

	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
		{
			tmp[k++] = arr[i++];
		}
		else
		{
			tmp[k++] = arr[j++];
		}
	}

	while (i <= mid)
	{
		tmp[k++] = arr[i++];
	}

	while (j <= right)
	{
		tmp[k++] = arr[j++];
	}

	for (i = left, k = 0; i <= right; i++, k++)
	{
		arr[i] = tmp[k];
	}
}

template<typename T>
void merge_sort_vector(std::vector<T>& arr, int p, int r)
{
	if (p < r)
	{
		int q = p + (r - p) / 2;
		merge_sort_vector(arr, p, q);
		merge_sort_vector(arr, q + 1, r);
		merge_vector(arr, p, q, r);
	}
}

template<typename T>
void set_data_vector(std::vector<T>& arr)
{
	int length{};
	std::cout << std::endl << "Enter number of elements: ";
	std::cin >> length;

	arr.resize(length);

	for (int i = 0; i < length; ++i)
	{
		std::cin >> arr[i];
	}
}

template<typename T>
void get_data_vector(std::vector<T>& arr)
{
	for (int i : arr)
	{
		std::cout << std::endl << i;
	}
}
