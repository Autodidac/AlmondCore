#pragma once

#include "WaitFreeQueue.h"

#include <condition_variable>
#include <functional>
#include <thread>
#include <vector>

class ThreadPool {
public:
    explicit ThreadPool(size_t threadCount);
    ~ThreadPool();

    void enqueue(std::function<void()> job);

private:
    void workerThread();

    std::vector<std::thread> workers;
    WaitFreeQueue<std::function<void()>> jobQueue;
    std::atomic<bool> isRunning;
    std::condition_variable condition;
};

ThreadPool::ThreadPool(size_t threadCount)
    : jobQueue(std::thread::hardware_concurrency()), isRunning(true) {
    for (size_t i = 0; i < threadCount; ++i) {
        workers.emplace_back(&ThreadPool::workerThread, this);
    }
}

ThreadPool::~ThreadPool() {
    isRunning = false; // Stop accepting new jobs
    condition.notify_all(); // Wake up all worker threads
    for (auto& worker : workers) {
        worker.join(); // Wait for all worker threads to finish
    }
}

void ThreadPool::enqueue(std::function<void()> job) {
    jobQueue.enqueue(std::move(job));
    condition.notify_one(); // Notify one worker thread
}

void ThreadPool::workerThread() {
    while (isRunning) {
        std::function<void()> job;
        if (jobQueue.dequeue(job)) { // Dequeue returns true if successful
            job(); // Execute the job
        }
        else {
            std::this_thread::yield(); // Yield to avoid busy-waiting
        }
    }
}