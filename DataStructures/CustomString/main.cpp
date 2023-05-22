#include "String.h"

int main()
{
	String a("Elen");
	String b = "len";
	String c;
	a += b;
	std::cout << b.compare(b);
	a.print();
	c.copy(a);
	c.print();
	c.find(b);

	String::iterator it = c.begin();
	std::cout << std::endl;
	for (it; it != c.end(); it++)
	{
		std::cout << *it;
	}
}
