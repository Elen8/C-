#include <iostream>

void heapify(int*& arr, int i, int length)
{
    int l = 2 * i;
    int r = 2 * i + 1;
    int max{};
    if (l < length && arr[l] > arr[i])
        max = l;
    else
        max = i;

    if (r < length && arr[r] > arr[max])
        max = r;
    if (max != i)
    {
        std::swap(arr[i], arr[max]);
        heapify(arr, max, length);
    }
}

void build_heap(int*& arr, int length)
{
    for (int i = (length / 2 - 1); i >= 0; i--)
    {
        heapify(arr, i, length);
    }
}

void heapsort(int*& arr, int length)
{
    build_heap(arr, length);
    for (int i = length - 1; i >= 1; i--)
    {
        std::swap(arr[0], arr[i]);
        length = length - 1;
        heapify(arr, 0, length);
    }
}

void input(int*& arr, int length)
{
    arr = new int[length];
    for (int i = 0; i < length; i++)
    {
        std::cin >> arr[i];
    }
}

void output(int*& arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }
}

int main()
{
    int* arr;
    int length{};
    std::cout << "Enter number of elements: ";
    std::cin >> length;

    input(arr, length);
    build_heap(arr, length);
    output(arr, length);

    heapsort(arr, length);
    output(arr, length);
}
