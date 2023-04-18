#include <iostream>
#include <vector>
#include "insertion_sort.h"
#include "insertion_sort_unique.h"
#include "insertion_sort_vector.h"

int main()
{
	std::cout << "Enter the length of array: ";
	size_t length{};
	std::cin >> length;
	
	int* arr1 = new int[length];

	input_data(arr1, length);
	insertion_sort(arr1, length);
	output(arr1, length);

	delete[] arr1;
	
	std::unique_ptr<int[]> arr2(new int[length]);
	input_data_unique(arr2, length);
	insertion_sort_unique(arr2, length);
	output_unique(arr2, length);

	std::vector<int> arr3(length);
	input_data_vector(arr3, length);
	insertion_sort_vector(arr3, length);
	output_vector(arr3, length);
}
