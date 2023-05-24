#include "UniquePtr.h"
#include "SharedPtr.h"

template<typename T>
SmartPointer::UniquePtr<T> make_uptr(T ptr)
{
	return SmartPointer::UniquePtr<T>(new T(ptr));
}

template<typename T>
SmartPointer::UniquePtr<T>&& move_ptr(SmartPointer::UniquePtr<T>& ptr)
{
	return static_cast<SmartPointer::UniquePtr<T>&&>(ptr);
}

template<typename T>
SmartPointer::SharedPtr<T> make_shptr(T ptr)
{
	return SmartPointer::SharedPtr<T>(new T(ptr));
}

template<typename T>
SmartPointer::SharedPtr<T>&& move_ptr(SmartPointer::SharedPtr<T>& ptr)
{
	return static_cast<SmartPointer::SharedPtr<T>&&>(ptr);
}
