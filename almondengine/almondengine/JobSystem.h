#pragma once

#include <atomic>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <queue>
#include <thread>
#include <vector>

class JobSystem {
public:
    JobSystem(size_t threadCount);
    ~JobSystem();

    template<typename T>
    void enqueueJob(T job);

private:
    void workerThread();

    std::vector<std::thread> threads; // Store threads for job processing
    std::queue<std::function<void()>> jobs; // Job queue
    std::mutex queueMutex; // Mutex for queue access
    std::condition_variable condition; // Condition variable for synchronization
    std::atomic<bool> stop; // Atomic flag to stop threads
};

inline JobSystem::JobSystem(size_t threadCount) : stop(false) {
    for (size_t i = 0; i < threadCount; ++i) {
        threads.emplace_back(&JobSystem::workerThread, this); // Start worker threads
    }
}

inline JobSystem::~JobSystem() {
    stop = true; // Signal threads to stop
    condition.notify_all(); // Wake up all threads
    for (std::thread& thread : threads) {
        if (thread.joinable()) {
            thread.join(); // Wait for threads to finish
        }
    }
}

template<typename T>
void JobSystem::enqueueJob(T job) {
    {
        std::lock_guard<std::mutex> lock(queueMutex); // Lock the queue
        jobs.emplace(job); // Add job to the queue
    }
    condition.notify_one(); // Notify one waiting thread
}

inline void JobSystem::workerThread() {
    while (!stop) {
        std::function<void()> job;
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            condition.wait(lock, [this] { return stop || !jobs.empty(); }); // Wait for jobs

            if (stop && jobs.empty()) {
                return; // Exit if stopping
            }
            job = std::move(jobs.front()); // Get the job from the queue
            jobs.pop(); // Remove job from the queue
        }
        job(); // Execute the job
    }
}
