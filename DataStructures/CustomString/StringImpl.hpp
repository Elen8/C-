#include "String.h"
#include <iostream>

String::String(const char* newStr)
{
	const int size = std::strlen(newStr);
	str = new char[size + 1];
	std::memcpy(str, newStr, size);
	str[size] = '\0';
}

String::String()
{
	str = nullptr;
}

String::~String()
{
}

String String::operator=(const char* newStr)
{
	const int size = std::strlen(newStr);
	str = new char[size];

	for (int i = 0; i < size; i++)
		str[i] = newStr[i];

	return *this;
}

char String::operator[](size_t position)
{
	return str[position];
}

String& String::operator+=(String& newString)
{
	const int size = std::strlen(newString.str) + std::strlen(str);
	char* newStr = new char[size];

	int i = 0;
	std::memcpy(newStr, str, size);
	std::memcpy(newStr + std::strlen(newString.str) + 1, newString.str, size + 1);

	str = newStr;
	return *this;
}

int String::compare(String& s)
{
	return std::strcmp(str, s.str);
}

String& String::copy(String& s)
{
	if (str == nullptr)
		str = new char[std::strlen(s.str) + 1];

	std::memcpy(str, s.str, std::strlen(s.str) + 1);
	return *this;
}

size_t String::find(String& s)
{
	if (str != nullptr && std::strlen(str) >= std::strlen(s.str))
	{
		int i = 0;
		while (i < std::strlen(str))
		{
			if (str[i] == s.str[0])
			{
				int j = 0;
				while (str[i] == s.str[j])
				{
					++i;
					++j;
				}
				if (j == std::strlen(s.str))
				{
					return (i - std::strlen(s.str));
				}
			}
			else
				++i;
		}
	}
	else
	{
		std::cout << "Unknown command!";
		exit(1);
	}
}

void String::print()
{
	for (int i = 0; i < std::strlen(str); i++)
		std::cout << str[i];
}


String::iterator::iterator()
{
	i_ptr = nullptr;
}

char String::iterator::operator*()
{
	return *i_ptr;
}

char* String::iterator::operator->()
{
	return i_ptr;
}

String::iterator& String::iterator::operator++()
{
	i_ptr++;
	return *this;
}

String::iterator& String::iterator::operator++(int)
{
	i_ptr++;
	return *this;
}

String::iterator& String::iterator::operator--()
{
	i_ptr--;
	return *this;
}

String::iterator& String::iterator::operator--(int)
{
	i_ptr--;
	return *this;
}

const String::iterator String::begin() 
{
	iterator* it = new iterator;
	it->i_ptr = str;
	return *it;
}

const String::iterator& String::end() 
{
	iterator* it = new iterator;
	it->i_ptr = str + std::strlen(str);
	return *it;
}

bool String::iterator::operator!=(const String::iterator& it)
{
	return i_ptr != it.i_ptr;
}

bool String::iterator::operator==(const String::iterator& it)
{
	return i_ptr == it.i_ptr;
}
