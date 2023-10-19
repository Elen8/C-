
#ifndef THREADSAFEQUEUE_H
#define THREADSAFEQUEUE_H

#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

// This queue is designed to work for ex. in a server.
template <class T>
class ThreadSafeQueue
{
public:
    void push(T const&);
    // @Brief:  If you try to pop an item and if the queue is empty then
    //          it will wait until there will be an available item to pop.
    bool try_pop(T&);

private:
    std::queue<T> buffer;
    std::mutex mutex;
    std::condition_variable cv;
};

#include "ThreadSafeQueue.impl.hpp"

#endif // !THREADSAFEQUEUE_H
