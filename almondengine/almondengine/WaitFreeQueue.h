#pragma once

#include <atomic>
#include <vector>
#include <optional>

template<typename T>
class WaitFreeQueue {
public:
    explicit WaitFreeQueue(size_t capacity);
    bool enqueue(const T& item);
    bool dequeue(T& item);

private:
    std::vector<std::optional<T>> buffer;
    std::atomic<size_t> head;
    std::atomic<size_t> tail;
};

template<typename T>
WaitFreeQueue<T>::WaitFreeQueue(size_t capacity)
    : buffer(capacity), head(0), tail(0) {}

template<typename T>
bool WaitFreeQueue<T>::enqueue(const T& item) {
    size_t currentTail = tail.load();
    size_t nextTail = (currentTail + 1) % buffer.size();

    if (nextTail == head.load()) {
        return false; // Queue is full
    }

    buffer[currentTail] = item;
    tail.store(nextTail);
    return true;
}

template<typename T>
bool WaitFreeQueue<T>::dequeue(T& item) {
    size_t currentHead = head.load();

    if (currentHead == tail.load()) {
        return false; // Queue is empty
    }

    item = std::move(buffer[currentHead].value());
    buffer[currentHead].reset(); // Clear the value
    head.store((currentHead + 1) % buffer.size());
    return true;
}