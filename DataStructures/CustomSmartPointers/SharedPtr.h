#ifndef SHAREDPTR_H
#define SHAREDPTR_H

namespace SmartPointer
{
	template<typename T>
	class SharedPtr
	{
	public:
		SharedPtr();
		SharedPtr(std::nullptr_t);
		SharedPtr(T*);
		SharedPtr(const T*);
		SharedPtr(SharedPtr<T>&);
		SharedPtr(const SharedPtr<T>&);
		SharedPtr(SharedPtr<T>&&) noexcept;
		~SharedPtr();

	public:
		SharedPtr<T>& operator=(SharedPtr<T>&);
		SharedPtr<T>&& operator=(SharedPtr<T>&&);
		T* operator&();
		T operator*();
		size_t use_count() const;
		T get() const;

		friend std::ostream& operator<<(std::ostream& os, const SharedPtr<T>& ptr)
		{
			os << ptr.sh_ptr;
			return os;
		}


	private:
		T* sh_ptr = nullptr;
		size_t sh_counter = 0;
	};
}

#include "SharedPtrImpl.hpp"
#endif // !SHAREDPTR_H
