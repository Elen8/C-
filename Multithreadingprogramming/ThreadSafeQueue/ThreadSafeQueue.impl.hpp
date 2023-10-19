
#include "ThreadSafeQueue.h"

template<class T>
void ThreadSafeQueue<T>::push(T const& item) {
    std::lock_guard<std::mutex> lock(mutex);
    buffer.push(item);
    cv.notify_one();
}


template<class T>
bool ThreadSafeQueue<T>::try_pop(T& item) {
    std::unique_lock<std::mutex> lock(mutex);
    cv.wait(lock, [this] { return !buffer.empty(); });

    item = buffer.front();
    buffer.pop();
    return true;
}
