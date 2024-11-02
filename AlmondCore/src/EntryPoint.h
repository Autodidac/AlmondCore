#pragma once

#include "EntryPoint_Crossplatform.h"

#include <memory>
#include <optional>
#include <string>

#ifdef _MSC_VER
// Only for MSVC compilers
#pragma warning(disable : 4251)
#pragma warning(disable : 4273)
#endif

namespace almond {

    class ENTRYPOINTLIBRARY_API EntryPoint {
    public:
        EntryPoint(int width, int height, const std::wstring& title);
        ~EntryPoint() noexcept; // Marking as noexcept

        EntryPoint(EntryPoint&&) noexcept = default;
        EntryPoint& operator=(EntryPoint&&) noexcept = default;

        void show() const;
        bool pollEvents() const;

        // Static method for creating and accessing EntryPoint_Crossplatform
        static std::optional<std::unique_ptr<EntryPoint_Crossplatform>>& getEntryPoint(); // Declaration only

    private:
        class ENTRYPOINTLIBRARY_API Impl {
        public:
            Impl(int width, int height, const std::wstring& title);
            ~Impl() noexcept; // Marking as noexcept

            void show() const;
            bool pollEvents() const;

        private:
            int width;
            int height;
            std::wstring title;
            // Additional necessary members, e.g., window handle
        };

        std::unique_ptr<Impl> pImpl; // Pointer to implementation
    };

    // Definition of the static member in the corresponding .cpp file
    inline std::optional<std::unique_ptr<EntryPoint_Crossplatform>>& EntryPoint::getEntryPoint() {
        static std::optional<std::unique_ptr<EntryPoint_Crossplatform>> entryPoint;
        return entryPoint;
    }

    // Export function for creating the EntryPoint instance
    extern "C" ENTRYPOINTLIBRARY_API EntryPoint* CreateEntryPoint(int width, int height, const wchar_t* title);

} // namespace almond