#include "Coroutine.h"
#include "EntryPoint.h"
#include "EntryPoint_Headless.h"
#include "ThreadPool.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <optional>

// Coroutine function for game logic
inline almond::Coroutine gameLogicCoroutine() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Logic Coroutine Updated..." << std::endl;
        co_yield i; // Yield game logic frame state
    }
}

// Coroutine for simulating physics updates
inline almond::Coroutine physicsCoroutine() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Physics Coroutine Updated..." << std::endl;
        co_yield i;
    }
}

// Coroutine for simulating audio updates
inline almond::Coroutine audioCoroutine() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Audio Coroutine Updated..." << std::endl;
        co_yield i;
    }
}

// Coroutine for simulating game system updates
inline almond::Coroutine gameSystemCoroutine() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Game Coroutine Updated..." << std::endl;
        co_yield i;
    }
}

int main() {
    std::cout << "Running headless application...\n";

    // Initialize thread pool with available hardware concurrency minus 1 thread
    ThreadPool threadPool(std::thread::hardware_concurrency() - 1);

    // Example coroutine instances for different systems
    auto gameLogic = gameLogicCoroutine();
    auto physics = physicsCoroutine();
    auto audio = audioCoroutine();
    auto gameSystem = gameSystemCoroutine();

    // Main loop for coroutine-based game logic, physics, audio, etc.
    try {
        bool gameLogicRunning = true;
        bool physicsRunning = true;
        bool audioRunning = true;
        bool gameSystemRunning = true;

        std::cout << "Main Thread..." << std::endl;

        // Main application loop
        while (gameLogicRunning || physicsRunning || audioRunning || gameSystemRunning) {
            if (gameLogicRunning) {
                gameLogicRunning = gameLogic.resume();
                std::cout << "Game logic yielded: " << gameLogic.current_value() << std::endl;
            }

            if (physicsRunning) {
                physicsRunning = physics.resume();
                std::cout << "Game physics yielded: " << physics.current_value() << std::endl;
            }

            if (audioRunning) {
                audioRunning = audio.resume();
                std::cout << "Game audio yielded: " << audio.current_value() << std::endl;
            }

            if (gameSystemRunning) {
                gameSystemRunning = gameSystem.resume();
                std::cout << "Game System yielded: " << gameSystem.current_value() << std::endl;
            }

            // Optionally, use thread pool for heavy tasks like loading resources
            threadPool.enqueue([] {
                std::cout << "Heavy asset loading on thread." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulating work
                });
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
