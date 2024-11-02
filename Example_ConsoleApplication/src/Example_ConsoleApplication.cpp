#include <iostream>
#include <stdexcept>
#include <memory>
#include <thread>
#include "..\..\AlmondCore\src\AlmondCore.h" 

// No explicit int main() is required
int width = 800;
int height = 600; 
const wchar_t* title = L"Almond Core Example";


// Structure to handle initialization and run logic
struct EntryPointInitializer {
    EntryPointInitializer(int width, int height, const wchar_t* title) {
        // Create the EntryPoint instance
     /*   auto entryPoint = almond::CreateEntryPoint(width, height, title);

        // Check if the EntryPoint instance is valid
        if (entryPoint) {
            entryPoint->show();

            // Polling events (dummy loop for demonstration)
            while (entryPoint->pollEvents()) {
                // Simulate some processing
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        } else {
            throw std::runtime_error("Failed to create EntryPoint instance.");
        }

        // Clean up (assuming you implement a destructor in EntryPoint)
        delete entryPoint;*/
    }
};

// Example usage to trigger initialization
EntryPointInitializer init(width, height, title);
