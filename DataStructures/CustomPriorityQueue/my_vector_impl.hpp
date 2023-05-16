#include <iostream>
#include "my_vector.h"
#include <map>

enum class ERRORS { VectorIsEmpty, IndexOutOfRange };
std::map<ERRORS, std::string> errors{ {ERRORS::VectorIsEmpty , "ERROR: Vector is empty.\n"} , {ERRORS::IndexOutOfRange, "ERROR:Index is out of range.\n"} };

template<typename T>
vec::my_vector<T>::my_vector()
{
	v_size = 0;
	v_capacity = 0;
	v_ptr = nullptr;
}

template<typename T>
inline vec::my_vector<T>::my_vector(my_vector<T>& new_vec)
{
	v_ptr = new_vec.v_ptr;
	v_size = new_vec.v_size;
	v_capacity = new_vec.v_capacity;
}

template<typename T>
inline vec::my_vector<T>::my_vector(int size, int elements)
{
	v_size = size;
	v_capacity = v_size * 2;
	v_ptr = new T[v_capacity];
	for (int i = 0; i < v_size; i++)
	{
		v_ptr[i] = elements;
	}
}

template<typename T>
inline vec::my_vector<T>::my_vector(std::initializer_list<T> arr)
{
	v_size = arr.size();
	v_capacity = v_size * 2;
	v_ptr = new T[v_capacity];
	for (int i = 0; i < v_size; i++)
	{
		v_ptr[i] = *(arr.begin() + i);
	}
}

template<typename T>
inline vec::my_vector<T>::~my_vector()
{
}

template<typename T>
vec::my_vector<T>& vec::my_vector<T>::operator=(my_vector<T> new_vec)
{
	if (this == &new_vec)
		return *this;

	if (new_vec.size() <= v_size)
	{
		for (int i = 0; i < new_vec.size(); ++i)
		{
			v_ptr[i] = new_vec[i];
			v_size = static_cast<size_t>(i) + 1;
		}
	}
	else
	{
		reserve(new_vec.capacity());
		for (int i = 0; i < new_vec.size(); ++i)
		{
			v_ptr[i] = new_vec[i];
			v_size = static_cast<size_t>(i) + 1;
		}
		v_capacity = new_vec.capacity();
	}
	return new_vec;
}

template<typename T>
T& const vec::my_vector<T>::at(size_t pos) const
{
	try
	{
		if (pos < v_size)
		{
			return v_ptr[pos];
		}
		else
		{
			throw ERRORS::IndexOutOfRange;
		}
	}
	catch (ERRORS e)
	{
		std::cout << errors[e];
		exit(1);
	}
}

template<typename T>
T& vec::my_vector<T>::operator[](int i)
{
	return *(v_ptr + i);
}

template<typename T>
T& vec::my_vector<T>::front() const
{
	if (this->empty())
	{
		return;
	}
	return v_ptr[0];
}

template<typename T>
T& vec::my_vector<T>::back() const
{
	if (this->empty())
	{
		return;
	}
	return v_ptr[v_size - 1];
}

template<typename T>
inline typename vec::my_vector<T>::iterator vec::my_vector<T>::begin()
{
	return my_vector<T>::iterator(&v_ptr[0]);
}

template<typename T>
typename vec::my_vector<T>::iterator vec::my_vector<T>::end()
{
	return my_vector<T>::iterator(&v_ptr[v_size]);
}

template<typename T>
bool vec::my_vector<T>::empty() const
{
	if (v_size == 0)
		return true;
	return false;
}

template<typename T>
size_t vec::my_vector<T>::size() const
{
	return v_size;
}

template<typename T>
size_t vec::my_vector<T>::max_size() const
{
	return v_capacity;
}

template<typename T>
void vec::my_vector<T>::reserve(size_t new_capacity)
{
	if (new_capacity <= v_capacity) return;

	T* new_ptr = new T[new_capacity];
	for (int i = 0; i < v_size; ++i)
	{
		new_ptr[i] = v_ptr[i];
	}

	//std::copy(v_ptr, v_ptr + v_capacity, new_ptr);
	delete[] v_ptr;

	v_ptr = new_ptr;
	
	v_capacity = new_capacity;
}

template<typename T>
const size_t vec::my_vector<T>::capacity() const
{
	return v_capacity;
}

template<typename T>
void vec::my_vector<T>::shrink_to_fit()
{
	for (int i = v_size + 1; i <= v_capacity; i++)
	{
		v_ptr[i].~T();
	}
	v_capacity = v_size;
}

template<typename T>
void vec::my_vector<T>::clear()
{
	for (int i = 0; i < v_size; ++i)
	{
		v_ptr[i] = 0;
	}
}

template<typename T>
void vec::my_vector<T>::insert(int pos, const T& element)
{
	reserve(v_size + 1);
	v_size++;
	T* new_ptr = new T[v_size];
	for (int i = 0; i < pos; ++i)
	{
		new_ptr[i] = v_ptr[i];
	}

	new_ptr[pos] = element;
	for (int i = pos + 1; i < v_size; ++i)
	{
		new_ptr[i] = v_ptr[i - 1];
	}

	v_ptr = new_ptr;

	new_ptr = nullptr;
	delete[] new_ptr;
}

template<typename T>
void vec::my_vector<T>::insert_range()
{

}

template<typename T>
void vec::my_vector<T>::emplace(int pos, const T& element)
{
	v_ptr[pos] = element;
}

template<typename T>
void vec::my_vector<T>::push_back(const T& element)
{
	if (capacity() == 0)
	{
		reserve(2);
	}
	else if (v_size == v_capacity)
	{
		reserve(v_size * 2);
	}

	v_ptr[v_size] = element;
	v_size++;
}

template<typename T>
void vec::my_vector<T>::emplace_back(const T& element)
{
	v_ptr[v_size - 1] = element;
}

template<typename T>
void vec::my_vector<T>::append_range()
{
}

template<typename T>
void vec::my_vector<T>::pop_back()
{
	try
	{
		if (this->empty())
		{
			throw ERRORS::VectorIsEmpty;
		}
	}
	catch (ERRORS e)
	{
		std::cout << errors[e];
		exit(1);
	}

	v_ptr[v_size - 1].~T();
	v_size--;
}

template<typename T>
void vec::my_vector<T>::resize(size_t new_size)
{
	if (new_size >= v_size)
	{
		reserve(new_size);

		for (int i = v_size; i < new_size; ++i)
			v_ptr[i] = T();

		v_size = new_size;
	}
}

template<typename T>
void vec::my_vector<T>::swap(size_t a, size_t b)
{
	try
	{
		if (v_size == 0)
		{
			throw ERRORS::VectorIsEmpty;
		}

	}
	catch (ERRORS e)
	{
		std::cout << errors[e];
		exit(1);
	}
	T temp = v_ptr[a];
	v_ptr[a] = v_ptr[b];
	v_ptr[b] = temp;
}

template<typename T>
inline vec::my_vector<T>::iterator::iterator(T* new_ptr)
{
	I_ptr = new_ptr;
}

template<typename T>
typename inline T& vec::my_vector<T>::iterator::operator*() const
{
	return *I_ptr;
}

template<typename T>
typename inline T& vec::my_vector<T>::iterator::operator->() const
{
	return I_ptr;
}

template<typename T>
typename inline vec::my_vector<T>::iterator& vec::my_vector<T>::iterator::operator++()
{
	I_ptr++;
	return *this;
}

template<typename T>
typename inline vec::my_vector<T>::iterator& vec::my_vector<T>::iterator::operator--()
{
	I_ptr--;
	return *this;
}

template<typename T>
typename inline T& vec::my_vector<T>::iterator::operator[](std::ptrdiff_t offset)
{
	return *(I_ptr + offset);
}

template<typename T>
inline bool vec::my_vector<T>::iterator::operator==(const iterator& ob)
{
	return (*I_ptr == *ob.I_ptr);
}

template<typename T>
inline bool vec::my_vector<T>::iterator::operator!=(const iterator& ob)
{
	return (*I_ptr != *ob.I_ptr);
}
