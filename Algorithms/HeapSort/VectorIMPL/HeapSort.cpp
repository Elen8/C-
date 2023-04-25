#include <iostream>
#include <vector>

template<typename T>
void heapify(std::vector<T>& arr, int i, int N)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int max = i;
    if (l < N && arr[l] > arr[max])
        max = l;

    if (r < N && arr[r] > arr[max])
        max = r;
    if (max != i)
    {
        std::swap(arr[i], arr[max]);
        heapify(arr, max, arr.size());
    }
}

template<typename T>
void build_heap(std::vector<T>& arr)
{
    for (int i = (arr.size() / 2 - 1); i >= 0; i--)
    {
        heapify(arr, i, arr.size());
    }
}

template<typename T>
void heapsort(std::vector<T>& arr)
{
    build_heap(arr);
    for (int i = arr.size() - 1; i > 0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, 0, arr.size());
    }
}

template<typename T>
void input(std::vector<T>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        std::cin >> arr[i];
    }
}

template<typename T>
void output(std::vector<T>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }
}

int main()
{
    int length{};
    std::cout << "Enter number of elements: ";
    std::cin >> length;
    std::vector<int> arr(length);

    input(arr);
    build_heap(arr);
    output(arr);

    heapsort(arr);
    output(arr);
}
