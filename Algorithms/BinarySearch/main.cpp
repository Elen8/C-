#include <iostream>
#include "BinarySearch.h"

int main()
{
	std::cout << "Enter number of elements: ";
	size_t size{};

	std::cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}

	std::cout << "Enter wanted number: ";
	int number;
	std::cin >> number;

	std::cout << BinarySearch(arr, number, 0, size - 1);
}
