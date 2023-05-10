#include "my_vector.h"
#include <iostream>

int main()
{
	vec::my_vector<int> vec;
	std::cout << vec.size() << std::endl;
	//vec.swap(1, 2);
	vec.push_back(48);
	vec::my_vector<int> new_vec({ 3, 5 });
	for (vec::my_vector<int>::iterator i = new_vec.begin(); i != new_vec.end(); ++i)
	{
		std::cout << *i << std::endl;
	}

	for (vec::my_vector<int>::iterator i = vec.begin(); i != vec.end(); ++i)
	{
		std::cout << *i << std::endl;
	}

	vec::my_vector<int> new_vec1 = { 3, 5 };
	std::cout << vec.size() << std::endl;
	std::cout << vec.at(0) << std::endl;
	/*my_vector<int>::iterator it = vec.begin();
	std::cout << *it;*/
	vec.push_back(50);
	vec.push_back(52);
	vec.push_back(54);
	vec.push_back(56);
	std::cout << vec.capacity() << std::endl;
	vec::my_vector<int> vec2;
	vec2 = vec;
	vec2.insert(0, 25);
	vec::my_vector<int>::iterator it = vec2.begin();
	for (it; it != vec2.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	it = vec2.begin();
	vec2.emplace(1, 96);
	vec2.pop_back();
	for (it; it != vec2.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	std::cout << vec2.size() << std::endl << vec2.capacity() << std::endl;
	//vec2.resize(10);
	//std::cout << vec2.size() << std::endl << vec2.capacity() << std::endl;

	vec2.swap(0, 2);
	it = vec2.begin();

	for (it; it != vec2.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
}
