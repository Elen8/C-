#include <iostream>

template <int n>
struct FibonacciNthNumber {
    enum { value = FibonacciNthNumber<n - 1>::value + FibonacciNthNumber<n - 2>::value };
};

template <>
struct FibonacciNthNumber<0> {
    enum { value = 0 };
};

template <>
struct FibonacciNthNumber<1> {
    enum { value = 1 };
};

int main()
{
    std::cout << FibonacciNthNumber<4>::value;
}
