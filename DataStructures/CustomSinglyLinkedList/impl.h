#include "CustomLinkedList.h"

template<typename T>
Node<T>::Node()
{
	m_nextptr = nullptr;
}

template<typename T>
Node<T>::Node(T data)
{
	this->m_nextptr = nullptr;
	this->m_data = data;
}

template<typename T>
Node<T>::~Node()
{
	delete m_nextptr;
}

template<typename T>
List<T>::List()
{
	m_head = nullptr;
}

template<typename T>
List<T>::~List()
{
}


template<typename T>
void List<T>::insertAt(int pos, int element)
{
	if (m_head == nullptr && pos != 0 || pos < 0)
	{
		std::cout << "Unknown action!\n";
		exit(1);
	}


	if (pos == 0)
	{
		Node<T>* newNode = new Node<T>;
		newNode->m_nextptr = m_head;
		newNode->m_data = element;
		m_head = newNode;
	}
	else if (m_head->m_nextptr != nullptr)
	{
		Node<T>* temp = m_head;
		while (pos != 1)
		{
			pos--;
			if (temp->m_nextptr == nullptr)
			{
				std::cout << "Out of range!\n";
				return;
			}
			temp = temp->m_nextptr;
		}
		Node<T>* newNode = new Node<T>;
		newNode->m_nextptr = temp->m_nextptr;
		temp->m_nextptr = newNode;
		newNode->m_data = element;
	}
	else
	{
		std::cout << "Out of range!\n";
		return;
	}
}

template<typename T>
void List<T>::deleteAt(int position)
{
	if (m_head == nullptr || position < 0)
	{
		std::cout << "Invalid action!\n";
		return;
	}

	Node<T>* tempNode = m_head;
	while (position != 1)
	{
		tempNode = tempNode->m_nextptr;
		position--;
	}

	if (tempNode->m_nextptr == nullptr)
	{
		//delete tempNode->m_nextptr;
		tempNode->m_nextptr = nullptr;
		return;
	}

	tempNode->m_nextptr = tempNode->m_nextptr->m_nextptr;
}

template<typename T>
void List<T>::print()
{
	if (m_head != nullptr)
	{
		Node<T>* tempHead = m_head;
		while (tempHead != nullptr)
		{
			std::cout << std::endl << tempHead->m_data;
			tempHead = tempHead->m_nextptr;
		}
	}
	else
		std::cout << "No elements in List\n";
}

template<typename T>
typename List<T>::iterator List<T>::begin() const
{
	return List<T>::iterator(m_head);
}

template<typename T>
typename List<T>::iterator List<T>::end() const
{
	return iterator(nullptr);
}

template<typename T>
void List<T>::push_back(T element)
{
	Node<T>* newNode = new Node<T>(element);

	if (m_head == nullptr)
	{
		this->m_head = newNode;
		return;
	}

	Node<T>* tempHead = m_head;
	while (tempHead->m_nextptr != nullptr)
	{
		tempHead = tempHead->m_nextptr;
	}

	tempHead->m_nextptr = newNode;
}

template<typename T>
void List<T>::pop_back()
{
	if (m_head->m_nextptr == nullptr)
	{
		m_head = nullptr;
		return;
	}
	Node<T>* temp = m_head;
	while (temp->m_nextptr->m_nextptr != nullptr)
	{
		temp = temp->m_nextptr;
	}
	delete temp->m_nextptr;
	temp->m_nextptr = nullptr;
}

template<typename T>
void List<T>::erase(int, int)
{
	//erases range of elements
}

template<typename T>
void List<T>::resize(int)
{

}

template<typename T>
void List<T>::swap(int, int)
{
	//swaps m_data of elements
}



template<typename T>
List<T>::iterator::iterator(Node<T>* new_ptr)
{
	i_ptr = new_ptr;
}

template<typename T>
List<T>::iterator::~iterator()
{
}

template<typename T>
typename List<T>::iterator& List<T>::iterator::operator++()
{
	if (i_ptr != nullptr && i_ptr->m_nextptr != nullptr)
	{
		i_ptr = i_ptr->m_nextptr;
		return *this;
	}
	else
	{
		exit(1);
	}
}

template<typename T>
typename List<T>::iterator& List<T>::iterator::operator++(int)
{
	if (i_ptr != nullptr && i_ptr->m_nextptr != nullptr)
	{
		i_ptr = i_ptr->m_nextptr;
		return *this;
	}
	else
	{
		exit(1);
	}
}


template<typename T>
typename List<T>::iterator& List<T>::iterator::operator--()
{
	return i_ptr--;
}

template<typename T>
typename List<T>::iterator& List<T>::iterator::operator--(int)
{
	return i_ptr--;
}

template<typename T>
typename T& List<T>::iterator::operator*()
{
	return this->i_ptr->m_data;
}

template<typename T>
typename T* List<T>::iterator::operator->()
{
	return i_ptr;
}

template<typename T>
bool List<T>::iterator::operator==(const iterator& ob)
{
	return (i_ptr == ob.i_ptr);
}

template<typename T>
bool List<T>::iterator::operator!=(const iterator& it)
{
	return (i_ptr != it.i_ptr);
}
