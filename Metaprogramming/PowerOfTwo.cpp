#include <iostream>
 
template <int n> 
struct PowerOfTwo
{
	enum { value = 2 * PowerOfTwo<n - 1>::value };
};
 
template <>
struct PowerOfTwo<0>
{
	enum { value = 1 };
};
 
int main()
{
	std::cout << PowerOfTwo<5>::value;
}
