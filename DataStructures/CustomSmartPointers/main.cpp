#include "UniquePtr.h"
#include "NonMemFunctions.h"
#include "SharedPtr.h"

int main()
{
	int* x = new int(3);
	SmartPointer::UniquePtr<int> uptr1;
	SmartPointer::UniquePtr<int> uptr2(nullptr);
	SmartPointer::UniquePtr<int> uptr3(x);

	int y = 4;
	SmartPointer::UniquePtr<int> uptr4 = make_uptr(y);
	SmartPointer::UniquePtr<int> uptr5(move_ptr(uptr4));

	std::cout << *uptr5;
	std::cout << *uptr3;

	SmartPointer::SharedPtr<int> shptr1;
	SmartPointer::SharedPtr<int> shptr2(nullptr);
	int* k = new int(8);
	SmartPointer::SharedPtr<int> shptr3(k);
	SmartPointer::SharedPtr<int> shptr4(shptr3);
	SmartPointer::SharedPtr<int> shptr5(move_ptr(shptr3));
	SmartPointer::SharedPtr<int> shptr6 = make_shptr(7);

	std::cout << *shptr5;
	std::cout << shptr5.get();
	std::cout << shptr5.use_count();
	std::cout << shptr3.use_count();
	std::cout << shptr6.get();
}
