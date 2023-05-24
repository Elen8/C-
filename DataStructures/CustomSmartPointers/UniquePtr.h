#ifndef UNIQUEPTR_H
#define UNIQUEPTR_H
#include <iostream> 

namespace SmartPointer
{
	template<typename T>
	class UniquePtr
	{
	public:
		UniquePtr();
		UniquePtr(std::nullptr_t);
		UniquePtr(T*);
		UniquePtr(UniquePtr<T>&) = delete;
		UniquePtr(UniquePtr<T>&&) noexcept;
		~UniquePtr();

		UniquePtr<T>& operator=(const UniquePtr<T>&) = delete;
		UniquePtr<T>& operator=(UniquePtr<T>&&);
		T operator*();
		T* operator&();
		friend std::ostream& operator<<(std::ostream& os, const UniquePtr<T>& ptr)
		{
			os << ptr.u_ptr;
			return os;
		}

	private:
		T* u_ptr = nullptr;
	};
}

#include "UniquePtrImpl.hpp"
#endif // !UNIQUEPTR_H
