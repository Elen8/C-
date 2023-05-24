#include "SharedPtr.h"

template<typename T>
SmartPointer::SharedPtr<T>::SharedPtr()
{
	sh_ptr = nullptr;
	sh_counter = 0;
}

template<typename T>
SmartPointer::SharedPtr<T>::SharedPtr(std::nullptr_t)
{
	sh_ptr = nullptr;
	sh_counter = 0;
}

template<typename T>
SmartPointer::SharedPtr<T>::SharedPtr(T* ptr)
{
	sh_counter = 0;
	sh_ptr = ptr;
}

template<typename T>
SmartPointer::SharedPtr<T>::SharedPtr(const T* ptr)
{
	sh_counter += 1;
	sh_ptr = ptr;
}

template<typename T>
SmartPointer::SharedPtr<T>::SharedPtr(SmartPointer::SharedPtr<T>& ptr)
{
	sh_ptr = ptr.sh_ptr;
	ptr.sh_counter += 1;
}

template<typename T>
SmartPointer::SharedPtr<T>::SharedPtr(const SmartPointer::SharedPtr<T>& ptr)
{
	sh_ptr = ptr.sh_ptr;
	ptr.sh_counter += 1;
}

template<typename T>
SmartPointer::SharedPtr<T>::SharedPtr(SharedPtr<T>&& ptr) noexcept
{
	sh_ptr = ptr.sh_ptr;
	sh_counter = ptr.sh_counter;
	ptr.sh_ptr = nullptr;
}

template<typename T>
SmartPointer::SharedPtr<T>::~SharedPtr()
{
	if (sh_counter == 0)
		delete sh_ptr;
	else
		sh_counter -= 1;
}

template<typename T>
SmartPointer::SharedPtr<T>& SmartPointer::SharedPtr<T>::operator=(SharedPtr<T>& ptr)
{
	sh_ptr = ptr.sh_ptr;
	ptr.sh_counter = ptr.sh_counter + 1;
	return *this;
}

template<typename T>
SmartPointer::SharedPtr<T>&& SmartPointer::SharedPtr<T>::operator=(SmartPointer::SharedPtr<T>&& ptr)
{
	sh_ptr = ptr.sh_ptr;
	ptr.sh_counter = ptr.sh_counter + 1;
	return *this;
}

template<typename T>
T* SmartPointer::SharedPtr<T>::operator&()
{
	return this;
}

template<typename T>
T SmartPointer::SharedPtr<T>::operator*()
{
	return *sh_ptr;
}

template<typename T>
size_t SmartPointer::SharedPtr<T>::use_count() const
{
	return sh_counter;
}

template<typename T>
T SmartPointer::SharedPtr<T>::get() const
{
	return *sh_ptr;
}
