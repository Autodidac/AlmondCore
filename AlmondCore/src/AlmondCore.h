#pragma once

#include "Exports_DLL.h"
#include "LoadSave.h"
#include "Logger.h"
#include "Scene.h"
#include "ThreadPool.h"
#include "framework.h"
#include "Types.h"

#ifdef _MSC_VER
// Only for MSVC compilers
#pragma warning(disable : 4251)
#pragma warning(disable : 4273)
#endif

extern "C" std::function<void(void)> m_updateCallback;
void RegisterAlmondCallback(std::function<void(void)> callback);

namespace almond {

    class ENTRYPOINTLIBRARY_API AlmondCore {
    public:
        // Remove constructor from here
        AlmondCore(size_t numThreads, bool running, Scene* scene);
        void Run();
        void RunWin32Desktop(MSG msg, HACCEL hAccelTable);
        bool IsRunning() const;
        void SetRunning(bool running);

        void PrintFPS() const;
        void UpdateFPS();
        void SetFrameRate(unsigned int targetFPS);

        static void RegisterCallbackUpdate(std::function<void()> callback) {
            ::RegisterAlmondCallback(callback);
        }

    private:
        bool m_running;
        Scene* m_scene;
        ThreadPool m_jobSystem;

        almond::SaveSystem m_saveSystem;
        std::vector<Event> m_events;

        void Serialize(const std::string& filename, const std::vector<Event>& events);
        void Deserialize(const std::string& filename, std::vector<Event>& events);

        void LimitFrameRate(std::chrono::steady_clock::time_point& lastFrame);

        int m_frameCount = 0;
        float m_fps = 0.0f;
        std::chrono::steady_clock::time_point m_lastSecond;
        unsigned int m_targetFPS = 120;
        bool m_frameLimitingEnabled = false;
        std::chrono::steady_clock::time_point m_lastFrame = std::chrono::steady_clock::now();

        float m_totalTime = 0.0f;
        int m_totalFrames = 0;
        float m_averageFPS = 0.0f;

        int m_saveIntervalMinutes = 15;
        std::chrono::steady_clock::time_point m_lastSave = std::chrono::steady_clock::now();
    };

    // Create a factory function for creating an AlmondCore instance
    extern "C" AlmondCore* CreateAlmondCore(size_t numThreads, bool running, Scene* scene);
    extern "C" void Run(AlmondCore& core);

} // namespace almond
