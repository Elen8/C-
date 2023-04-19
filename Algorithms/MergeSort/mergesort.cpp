#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right)
{
	int i = left, j = mid + 1, k = 0;
	std::vector<int> tmp(right - left + 1);

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

void merge_sort(std::vector<int>& arr, int p, int r)
{
	if (p < r)
	{
		int q = p + (r - p) / 2;
		merge_sort(arr, p, q);
		merge_sort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}

void set_data(std::vector<int>& arr)
{
	int length{};
	std::cout << "Enter number of elements: ";
	std::cin >> length;

	arr.resize(length);

	for (int i = 0; i < length; ++i)
	{
		std::cin >> arr[i];
	}
}

void get_data(std::vector<int>& arr)
{
	for (int i : arr)
	{
		std::cout << std::endl << i;
	}
}

int main()
{
	std::vector<int> arr{};
	set_data(arr);
	merge_sort(arr, 0, arr.size() - 1);
	get_data(arr);
}
