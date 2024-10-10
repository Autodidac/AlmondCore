#pragma once

#include <chrono>

class TimeKeeper {
public:
    void start();
    void stop();
    double elapsed() const;

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> endTime;
    bool running = false;
};

inline void TimeKeeper::start() {
    startTime = std::chrono::high_resolution_clock::now();
    running = true;
}

inline void TimeKeeper::stop() {
    endTime = std::chrono::high_resolution_clock::now();
    running = false;
}

inline double TimeKeeper::elapsed() const {
    return running ? std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - startTime).count()
        : std::chrono::duration<double>(endTime - startTime).count();
}