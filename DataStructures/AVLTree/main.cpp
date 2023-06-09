#include "AVLtree.h"

int main()
{
	AVLtree<int> tree;
	tree.insert(10);
	tree.insert(20);



	tree.insert(30);
	tree.insert(40);
	tree.insert(50);


	tree.insert(25);

	tree.print();

	tree.del(40);
	tree.del(50);

	//std::cout << std::endl;
	//tree.print();


	//tree.del(30);

	std::cout << std::endl;
	tree.print();
}
