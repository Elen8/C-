#ifndef CUSTOMLINKEDLIST
#define CUSTOMLINKEDLIST

#include <iostream>

template <typename T>
class Node
{
public:
	Node();
	Node(T);
	~Node();

public:
	Node<T>* m_nextptr;
	T m_data;
};

template <typename T>
class List
{
public:
	List();
	~List();

	class iterator
	{
	public:
		Node<T>* i_ptr;

	public:
		iterator(Node<T>*);
		~iterator();

		iterator& operator++();
		iterator& operator++(int);
		iterator& operator--();
		iterator& operator--(int);

		T& operator*();
		T* operator->();

		bool operator==(const iterator&);
		bool operator!=(const iterator&);
	};

public:
	void insertAt(int, int);
	void deleteAt(int);
	void print();

	iterator begin() const;
	iterator end() const;

	void push_back(T);
	void pop_back();
	void erase(int, int);
	void resize(int);
	void swap(int, int);


private:
	Node<T>* m_head;
};

#include "impl.hpp"

#endif
