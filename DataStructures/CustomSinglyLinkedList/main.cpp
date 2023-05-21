#include "CustomLinkedList.h"

int main()
{
	List<int> myList;
	myList.print();
	myList.insertAt(0, 3);
	myList.push_back(10);
	myList.push_back(4);
	myList.push_back(7);
	myList.push_back(25);
	myList.pop_back();
	myList.print();
	myList.deleteAt(3);
	myList.print();

	//List<int>::iterator it = myList.begin();
	//std::cout << std::endl;

	//for (it; it != myList.end(); it++)
	//{
	//	std::cout << *it << std::endl;
	//}

}
