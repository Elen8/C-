#include "UniquePtr.h"

template<typename T>
SmartPointer::UniquePtr<T>::UniquePtr()
{
	if (u_ptr == nullptr)
		u_ptr = new T;
	else
		std::cout << "You can't new this pointer!\n";
}

template<typename T>
SmartPointer::UniquePtr<T>::UniquePtr(std::nullptr_t)
{
	u_ptr = nullptr;
}

template<typename T>
SmartPointer::UniquePtr<T>::UniquePtr(T* ptr)
{
	if (u_ptr == nullptr)
	{
		u_ptr = new T;
		u_ptr = ptr;
	}
	else
		std::cout << "Returns same u_ptr\n";
}

template<typename T>
SmartPointer::UniquePtr<T>::UniquePtr(SmartPointer::UniquePtr<T>&& uptr) noexcept
{
	if (u_ptr == nullptr)
	{
		u_ptr = new T;
		u_ptr = uptr.u_ptr;
		uptr.u_ptr = nullptr;
	}
	else
		std::cout << "You can't new this pointer!\n";
}

template<typename T>
SmartPointer::UniquePtr<T>::~UniquePtr()
{
	delete u_ptr;
}

template<typename T>
T SmartPointer::UniquePtr<T>::operator*()
{
	if (u_ptr == nullptr)
	{
		std::cout << "Calling to nullptr!";
		exit(1);
	}
	return *u_ptr;
}

template<typename T>
T* SmartPointer::UniquePtr<T>::operator&()
{
	return u_ptr;
}

template<typename T>
SmartPointer::UniquePtr<T>& SmartPointer::UniquePtr<T>::operator=(UniquePtr<T>&& ptr)
{
	delete u_ptr;
	u_ptr = ptr.u_ptr;
	ptr.u_ptr = nullptr;
	return *this;
}
