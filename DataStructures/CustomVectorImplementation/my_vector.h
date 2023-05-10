
#ifndef MY_VECTOR
#define MY_VECTOR

#include <memory>

namespace vec {

template<typename T>
class my_vector
{
public:
	class iterator
	{
	public:
		iterator(T*);
	public:
		T& operator*() const; //done
		T& operator->() const; //done
		iterator& operator++(); //done
		iterator& operator--(); //done
		T& operator[](std::ptrdiff_t); //done
		bool operator==(const iterator&); //done
		bool operator!=(const iterator&); //done

	public:
		T* I_ptr;
	};

public:
	my_vector(); //done
	my_vector(my_vector<T>&); //done
	my_vector(int, int); //done
	my_vector(std::initializer_list<T>); //done
	~my_vector(); //done

public:
	//assignments
	my_vector<T>& operator=(my_vector<T>); //done

	//element access
	T& const at(size_t) const; //done
	T& operator[](int i); //done
	T& front() const; //done
	T& back() const; //done

	//iterators
	iterator begin(); //done
	iterator end(); //done

	//capacity
	bool empty() const; //done
	size_t size() const;  //done
	size_t max_size() const; //done
	constexpr void reserve(size_t); //done
	const size_t capacity() const; //done
	void shrink_to_fit(); //done

	//modifiers
	void clear(); //done
	void insert(int, const T&); //done
	void insert_range(); //--
	void emplace(int, const T&); //done
	void push_back(const T&); //done
	void emplace_back(const T&); //done
	void append_range(); //--
	void pop_back(); //done
	void resize(size_t); //done
	void swap(size_t, size_t); //done

private:
	size_t v_size;
	size_t v_capacity;
	T* v_ptr;
};

} // namespace vec

#include "impl.hpp"

#endif //MY_VECTOR
