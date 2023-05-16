#include "PriorityQueue.h"

size_t left(size_t index)
{
    return 2 * index + 1;
}

size_t rigth(size_t index)
{
    return 2 * index + 2;
}

template<typename T, typename Container, typename Compare>
PriorityQueue<T, Container, Compare>::PriorityQueue()
{
    m_size = 0;
    build();
}

template<typename T, typename Container, typename Compare>
PriorityQueue<T, Container, Compare>::~PriorityQueue()
{
}

template<typename T, typename Container, typename Compare>
void PriorityQueue<T, Container, Compare>::build()
{
    for (int i = size() / 2 - 1; i >= 0; i--)
    {
        heapify(i);
    }
}

template<typename T, typename Container, typename Compare>
void PriorityQueue<T, Container, Compare>::heapify(int i)
{
    int l = left(i);
    int r = rigth(i);
    int max = i;

    if (l < size() && !m_cmp(m_container[l], m_container[max]))
    {
        max = l;
    }
    if (r < size() && !m_cmp(m_container[r], m_container[max]))
    {
        max = r;
    }

    if (max != i)
    {
        std::swap(m_container[max], m_container[i]);
        heapify(max);
    }
}

template<typename T, typename Container, typename Compare>
T PriorityQueue<T, Container, Compare>::top()
{
    if (!size() != 0)
        return m_container[size() - 1];
}

template<typename T, typename Container, typename Compare>
constexpr size_t PriorityQueue<T, Container, Compare>::size() const
{
    return m_container.size();
}

template<typename T, typename Container, typename Compare>
void PriorityQueue<T, Container, Compare>::push(const T element)
{
    m_container.push_back(element);
    m_size++;
    heapsort();

}

template<typename T, typename Container, typename Compare>
void PriorityQueue<T, Container, Compare>::pop()
{
    if (size() == 0)
    {
        m_container.pop_back();
        heapify(0);
    }
}

template<typename T, typename Container, typename Compare>
void PriorityQueue<T, Container, Compare>::heapsort()
{
    build();
    int length = m_size;
    for (int i = m_size - 1; i >= 0; i--)
    {
        std::swap(m_container[i], m_container[0]);
        m_size--;
        heapify(0);
    }
    m_size = length;
}

template<typename T, typename Container, typename Compare>
void PriorityQueue<T, Container, Compare>::print()
{
    for (int i = 0; i < size(); i++)
    {
        std::cout << m_container[i] << std::endl;
    }
}
