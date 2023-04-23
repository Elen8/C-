#include "merge_sort.h"
#include <iostream>

void merge(int*& arr, int left, int mid, int right) //0 1 2
{
	int i = left, j = mid + 1, k = 0;
	int* tmp1 = new int[mid - left + 1];
	int* tmp2 = new int[right - mid];

	for (i; i <= mid; i++)
	{
		tmp1[k] = arr[i];
		k++;
	}

	k = 0;
	for (j; j <= right; j++)
	{
		tmp2[k] = arr[j];
		k++;
	}

	i = 0;
	j = 0;
	k = left;
	while (i < mid - left + 1 && j < right - mid)
	{
		if (tmp1[i] <= tmp2[j])
		{
			arr[k] = tmp1[i];
			k++;
			i++;
		}
		else
		{
			arr[k] = tmp2[j];
			j++;
			k++;
		}
	}

	while (i < mid - left + 1) {
		arr[k] = tmp1[i];
		k++;
		i++;
	}

	while (j < right - mid) {
		arr[k] = tmp2[j];
		k++;
		j++;
	}

	delete[] tmp1;
	delete[] tmp2;
}
//i  j
//15 46

void merge_sort(int*& arr, int p, int r) 
{
	if (p < r)
	{
		int q = p + (r - p) / 2;
		merge_sort(arr, p, q);           
		merge_sort(arr, q + 1, r);       
		merge(arr, p, q, r);             
	}
}


void set_data(int*& arr, int length)
{
	for (int i = 0; i < length; ++i)
	{
		std::cin >> arr[i];
	}
}

void get_data(int*& arr, int length)
{
	for (int i = 0; i < length; ++i)
	{
		std::cout << std::endl << "arr[" << i << "] = " << arr[i];
	}

	delete[] arr;
}
