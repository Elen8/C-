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


template <typename T>
class List
{
public:
	List();
	~List();

public:
	void insert(T);
	void deleteAt(int);
	void print();

private:
	Node<T>* m_head;
};

template<typename T>
List<T>::List()
{
	m_head = nullptr;
}

template<typename T>
List<T>::~List()
{
	delete m_head;
}


template<typename T>
void List<T>::insert(T element)
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
		delete tempNode->m_nextptr;
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

int main()
{
	List<int> myList;
	myList.print();
	myList.insert(3);
	myList.insert(10);
	myList.insert(4);
	myList.insert(7);
	myList.insert(25);
	myList.print();
	myList.deleteAt(3);
	myList.print();
}
