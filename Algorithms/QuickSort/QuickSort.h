#ifndef QUICKSORT
#define QUICKSORT
#include <iostream>

int partition(int*& arr, int begin, int end)
{
	int pivot = arr[end];
	int lastSmallestIndex = begin - 1;
	for (int i = begin; i < end; i++)
	{
		if (pivot > arr[i])
		{
			lastSmallestIndex++;
			std::swap(arr[i], arr[lastSmallestIndex]);
		}

	}
	lastSmallestIndex++;
	std::swap(arr[end], arr[lastSmallestIndex]);
	return lastSmallestIndex;
}

void quicksort(int*& arr, int begin, int end)
{
	if (begin >= end)
		return;

	int pivot = partition(arr, begin, end);
	quicksort(arr, begin, pivot - 1);
	quicksort(arr, pivot + 1, end);
}

#endif //QuickSort
