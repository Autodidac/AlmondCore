#pragma once

#include "EventManager.h"
#include "ThreadPool.h"
#include "MovementEvent.h"
#include "Logger.h"
#include "Scene.h"

#include <chrono>
#include <iostream>
#include <memory>
#include <stack>
#include <thread>
#include <vector>

// Main engine class to tie everything together
namespace almond {
class Engine {
public:
    Engine(size_t threadCount);
    void run();
    void rewindTime();
    bool isTimeRewindable() const;
    void shutdown();
    Scene& getScene(); // Added method declaration

private:
    void initialize();
    void update(float deltaTime);
    void processEvents();
    void handleMovementEvent(const MovementEvent& movementEvent);
    void saveState();
    void restoreState();

    Scene scene;
    ThreadPool jobSystem;
    EventManager eventManager;
    std::stack<std::unique_ptr<Scene>> sceneHistory; // Store scenes as unique pointers
    const size_t maxHistorySize = 10;
    Logger logger; // Logger instance

    static constexpr int maxFrames = 10; // Frame limit for run loop
};

inline Engine::Engine(size_t threadCount)
    : jobSystem(threadCount), logger("engine.log") {
    logger.log("Engine initialized.");
}

inline void Engine::initialize() {
   /* scene.load();
    if (!scene.isLoaded()) { // Assuming load returns a bool
        logger.log("Error loading scene!");
        return; // Early exit if loading fails
    }
    saveState();
    logger.log("Scene initialized and state saved.");*/
}

inline void Engine::update(float deltaTime) {
    // Always save the state each frame
    saveState();
}

inline void Engine::run() {
    initialize();

    float deltaTime = 0.016f; // Assume ~60 FPS
    int frameCount = 0;

    while (frameCount < maxFrames) { // Run for a maximum number of frames
        if (frameCount % 1 == 0) {
            auto movementEvent = std::make_unique<MovementEvent>(1, 1.0f, 0.0f);
            eventManager.addMovementEvent(std::move(movementEvent));
        }

        std::cout << "Frame " << frameCount << ": ";

        processEvents();
        update(deltaTime);

        scene.printEntityPositions();
        logger.log("Frame " + std::to_string(frameCount) + " processed.");


        std::this_thread::sleep_for(std::chrono::milliseconds(16));
        frameCount++;
    }

    while (frameCount > 1)
    {
        rewindTime();
        --frameCount;
    }

    shutdown();
}

inline void Engine::processEvents() {
    auto movementEvents = eventManager.getMovementEvents();
    for (const auto& movementEvent : movementEvents) {
        handleMovementEvent(*movementEvent); // Dereference the unique_ptr
    }
}

inline void Engine::handleMovementEvent(const MovementEvent& movementEvent) {
    scene.applyMovementEvent(movementEvent);
    movementEvent.print();
}

inline void Engine::saveState() {
    if (sceneHistory.size() >= maxHistorySize) {
        sceneHistory.pop(); // Remove the oldest state
    }

    auto savedScene = scene.clone(); // Create a unique_ptr using the clone method
    sceneHistory.push(std::move(savedScene)); // Save the current scene state

    logger.log("State saved. History size: " + std::to_string(sceneHistory.size()));
}

inline void Engine::restoreState() {
    if (!sceneHistory.empty()) {
        auto lastSavedScene = std::move(sceneHistory.top()); // Get the last saved scene
        sceneHistory.pop();

        scene = std::move(*lastSavedScene); // Move the state to the current scene

        logger.log("State restored. Remaining history: " + std::to_string(sceneHistory.size()));
    }
    else {
        std::cerr << "No states available to restore." << std::endl;
        logger.log("Error: No states available to restore.");
    }
}

inline void Engine::shutdown() {
    scene.unload();
    while (!sceneHistory.empty()) {
        sceneHistory.pop(); // Clear history stack
    }
    std::cout << "Engine unloaded scene successfully.\n";
    logger.log("Engine unloaded scene successfully.");
}

inline bool Engine::isTimeRewindable() const {
    return sceneHistory.size() > 1; // Ensure more than one state exists for rewinding
}

inline void Engine::rewindTime() {
    if (isTimeRewindable()) {
        restoreState();
        logger.log("Time rewound to previous state.");
    }
    else {
        std::cerr << "Cannot rewind time at this moment." << std::endl;
        logger.log("Warning: Cannot rewind time at this moment.");
    }
}

inline Scene& Engine::getScene() {
    return scene; // Return a reference to the scene
}
}