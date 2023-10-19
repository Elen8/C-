#include <iostream>
#include "ThreadSafeQueue.h"

std::mutex mtx;

void producer(ThreadSafeQueue<int>& tsq) {
    for (int i = 0; i < 5; ++i) {
        tsq.push(i);
        mtx.lock();
        std::cout << "Produced: " << i << std::endl;
        mtx.unlock();
    }
}

void consumer(ThreadSafeQueue<int>& tsq) {
    int data{};
    while (tsq.try_pop(data)) {
        mtx.lock();
        std::cout << "Consumed: " << data << std::endl;
        mtx.unlock();
    }
}

int main() {
    ThreadSafeQueue<int> buffer;
    std::thread ProducerThread(&producer, std::ref(buffer));
    std::thread ConsumerThread(&consumer, std::ref(buffer));

    ProducerThread.join();
    ConsumerThread.join();
    return 0;
}
