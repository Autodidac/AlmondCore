#include "AlmondCore.h"

#include <iostream>
#include <chrono>
#include <thread>

std::mutex callbackMutex;
std::function<void(void)> m_updateCallback;

void RegisterAlmondCallback(std::function<void(void)> callback) {
    std::lock_guard<std::mutex> lock(callbackMutex);
    m_updateCallback = callback;
}

namespace almond {

    // Constructor definition inside DLL
    AlmondCore::AlmondCore(size_t numThreads, bool running, Scene* scene)
        : m_jobSystem(numThreads), m_running(running), m_scene(scene),
        m_frameCount(0), m_lastSecond(std::chrono::steady_clock::now()) {}

    void AlmondCore::RunWin32Desktop(MSG msg, HACCEL hAccelTable) {
        auto lastFrame = std::chrono::steady_clock::now();
        auto lastSave = std::chrono::steady_clock::now();

        while (m_running) {
            auto currentTime = std::chrono::steady_clock::now();
            UpdateFPS();

            if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
                if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }

                if (msg.message == WM_QUIT) {
                    SetRunning(false);
                }
            }
            else {
                {
                    std::lock_guard<std::mutex> lock(callbackMutex);
                    if (m_updateCallback) {
                        m_updateCallback();
                    }
                }

                if (std::chrono::duration_cast<std::chrono::minutes>(currentTime - lastSave).count() >= m_saveIntervalMinutes) {
                    Serialize("savegame.dat", m_events);
                    lastSave = currentTime;
                    std::cout << "Game auto-saved." << std::endl;
                }

                if (m_frameLimitingEnabled) {
                    LimitFrameRate(lastFrame);
                }
            }
        }
    }

    void AlmondCore::Run() {
        auto lastFrame = std::chrono::steady_clock::now();
        auto lastSave = std::chrono::steady_clock::now();

        while (m_running) {
            auto currentTime = std::chrono::steady_clock::now();

            {
                std::lock_guard<std::mutex> lock(callbackMutex);
                if (m_updateCallback) {
                    m_updateCallback();
                }
            }

            if (std::chrono::duration_cast<std::chrono::minutes>(currentTime - lastSave).count() >= m_saveIntervalMinutes) {
                //Serialize("savegame.dat", m_events);
                lastSave = currentTime;
                std::cout << "Game auto-saved." << std::endl;
            }
            
            if (m_frameLimitingEnabled) {
                LimitFrameRate(lastFrame);
            }
        }
    }
    
    void Run(AlmondCore& core) {

        core.Run();
    }

    // Factory function to create AlmondCore instance
    AlmondCore* CreateAlmondCore(size_t numThreads, bool running, Scene* scene) {
        return new AlmondCore(numThreads, running, scene);
    }

    //void RegisterAlmondCallback(std::function<void(void)> callback)
   // {
   // }

    void AlmondCore::SetRunning(bool running) {
        m_running = running;
    }

    bool AlmondCore::IsRunning() const {
        return m_running;
    }

    void AlmondCore::SetFrameRate(unsigned int targetFPS) {
        m_targetFPS = targetFPS;
        m_frameLimitingEnabled = true;
    }

    void AlmondCore::UpdateFPS() {
        m_frameCount++;
        auto now = std::chrono::steady_clock::now();
        m_totalTime += std::chrono::duration_cast<std::chrono::milliseconds>(now - m_lastFrame).count();
        m_lastFrame = now;

        if (m_totalTime > 1000) {
            m_fps = static_cast<float>(m_frameCount) / (m_totalTime / 1000.0f);
            m_totalTime = 0.0f;
            m_frameCount = 0;
            m_lastSecond = now;
        }
    }

    void AlmondCore::PrintFPS() const {
        std::cout << "Current FPS: " << m_fps << std::endl;
    }

    void AlmondCore::LimitFrameRate(std::chrono::steady_clock::time_point& lastFrame) {
        auto now = std::chrono::steady_clock::now();
        auto frameDuration = now - lastFrame;
        auto targetFrameDuration = std::chrono::milliseconds(1000 / m_targetFPS);

        if (frameDuration < targetFrameDuration) {
            std::this_thread::sleep_for(targetFrameDuration - frameDuration);
        }
        lastFrame = now;
    }

    void AlmondCore::Serialize(const std::string& filename, const std::vector<Event>& events) {
        m_saveSystem.SaveGame(filename, events);
    }

    void AlmondCore::Deserialize(const std::string& filename, std::vector<Event>& events) {
        m_saveSystem.LoadGame(filename, events);
    }

} // namespace almond
