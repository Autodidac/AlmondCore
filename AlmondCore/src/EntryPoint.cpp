#include "EntryPoint.h"

namespace almond {

    EntryPoint::EntryPoint(int width, int height, const std::wstring& title) 
        : pImpl(std::make_unique<Impl>(width, height, title)) {
        // Any additional initialization can be added here
    }

    EntryPoint::~EntryPoint() noexcept = default; // No need to define further since unique_ptr will handle cleanup

    EntryPoint::Impl::Impl(int width, int height, const std::wstring& title)
        : width(width), height(height), title(title) {
        // Initialize resources (e.g., create window, set up graphics context)
    }

    EntryPoint::Impl::~Impl() noexcept {
        // Clean up resources (e.g., destroy window, release graphics context)
    }

    void EntryPoint::show() const {
        pImpl->show();
    }

    bool EntryPoint::pollEvents() const {
        return pImpl->pollEvents();
    }

    void EntryPoint::Impl::show() const {
        // Implementation to show the window
    }

    bool EntryPoint::Impl::pollEvents() const {
        // Implementation to poll for events
        return true; // Modify according to actual event handling logic
    }

}
