#include "QuickSort.h"
#include <iostream>
int main()
{
	std::cout << "Enter size of the array: ";
	int size{};
	std::cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}

	quicksort(arr, 0, size - 1);

	for (int i = 0; i < size; i++)
	{
		std::cout << std::endl << arr[i];
	}
}
