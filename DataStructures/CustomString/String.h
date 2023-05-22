#ifndef STRING_H
#define STRING_H

class String
{
public:
	class iterator
	{
	public:
		char* i_ptr;

		iterator();
		
		char operator*();
		char* operator->();

		iterator& operator++();
		iterator& operator++(int);
		iterator& operator--();
		iterator& operator--(int);
		bool operator!=(const iterator&);
		bool operator==(const iterator&);
	};

public:
	String(const char*);
	String();
	~String();

public:
	String operator=(const char*);
	char operator[](size_t);
	String& operator+=(String&);
	int compare(String&);
	String& copy(String&);
	size_t find(String&);

	const iterator begin();
	const iterator& end();

	void print();

private:
	char* str;
};

#include "StringImpl.hpp"

#endif 
