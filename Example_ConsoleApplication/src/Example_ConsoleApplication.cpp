//#include <iostream>
#include <stdexcept>
#include <memory>
#include <thread>
#include "..\..\AlmondCore\src\AlmondCore.h" // Ensure this includes your EntryPoint header

namespace almond {
    class EntryPoint; // Forward declaration if needed
    //almond::EntryPoint& ep();

}
// Structure to handle initialization and run logic
struct EntryPointInitializer {
    EntryPointInitializer(int width, int height, const wchar_t* title) {
        
        //ep().getEntryPoint();
    }
};

// Example usage to trigger initialization
EntryPointInitializer init(800, 600, L"Game Title");

// No explicit int main() is required here
