#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

int BinarySearch(int*& arr, int number, size_t begin, size_t end)
{
	if (number > arr[(end + begin) / 2])
		BinarySearch(arr, number, (end + begin) / 2 + 1, end);
	else if (number < arr[(end + begin) / 2])
		BinarySearch(arr, number, begin, (end + begin) / 2 - 1);
	else
		return (end + begin) / 2;
}

#endif
