template<typename T>
Stack<T>::Stack()
{
	m_size = 0;
	m_ptr = new T[MAX_SIZE];
}

template<typename T>
Stack<T>::~Stack()
{
	delete m_ptr;
}


template<typename T>
bool Stack<T>::empty()
{
	if (m_size == 0)
		return true;
	return false;
}

template<typename T>
void Stack<T>::push(const T& element)
{
	if (m_size <= MAX_SIZE - 1)
	{
		m_ptr[m_size] = element;
		m_size++;
	}
	else
		std::cout << "\nStack overflow\n";
}

template<typename T>
void Stack<T>::pop()
{
	if (empty())
	{
		std::cout << "\nStack is empty\n";
		return;
	}
	m_size--;
}

template<typename T>
T& Stack<T>::top() const
{
	return m_ptr[m_size - 1];
}

template<typename T>
const size_t Stack<T>::size() const
{
	return m_size;
}
