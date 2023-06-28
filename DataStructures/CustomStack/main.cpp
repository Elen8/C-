#include <iostream>
#include "Stack.h"

int main()
{
	Stack<int> s;
	s.push(2);
	s.push(3);
	int size = s.size();
	for (int i = 0; i < size; i++)
	{
		std::cout << s.top();
		s.pop();
	}
}
