#ifndef STACK_H
#define STACK_H
#include <iostream>

#define MAX_SIZE 50

template<typename T>
class Stack
{
public:
	Stack();
	~Stack();

public:
	bool empty();
	void push(const T&);
	void pop();
	T& top() const;
	const size_t size() const;

private:
	T* m_ptr;
	int m_size;
};

#include "CustomImpl.hpp"

#endif 
