#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
//#include <vector>
#include "my_vector.h"

template <typename T, typename Container = vec::my_vector<T>, typename Compare = std::less<typename Container::T>>
class PriorityQueue
{
public:
    PriorityQueue();
    ~PriorityQueue();

public:
    void build();
    void heapify(int);
    T top();
    size_t constexpr size() const;
    void push(const T);
    void pop();
    void heapsort();
    void print();

private:
    size_t m_size;
    Container m_container;
    Compare m_cmp;
};

#include "PriorityQueueImpl.hpp"

#endif // PRIORITYQUEUE_H
