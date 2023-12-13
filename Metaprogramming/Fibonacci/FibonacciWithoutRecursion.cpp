#include <iostream>

template <int n>
int FibonacciNthNumber()
{
    static_assert(n >= 0, "Invalid index passed to FibonacciNthNumber()");

    if constexpr (n == 0) return 0;
    else if constexpr (n == 1) return 1;
    else
        return FibonacciNthNumber<n - 1>() + FibonacciNthNumber<n - 2>();
};


int main()
{
    std::cout << FibonacciNthNumber<4>();
}
