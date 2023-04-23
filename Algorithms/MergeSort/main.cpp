#include <iostream>
#include "merge_sort_vector.h"
#include "merge_sort.h"

int main()
{
	std::vector<int> arr1{};
	set_data_vector(arr1);
	merge_sort_vector(arr1, 0, arr1.size() - 1);
	get_data_vector(arr1);


	int length{};
	std::cout << "Enter number of elements: ";
	std::cin >> length;

	int* arr2 = new int[length];

	set_data(arr2, length);
	merge_sort(arr2, 0, length - 1); 
	get_data(arr2, length);
}
