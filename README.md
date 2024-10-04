# AlmondCore

AlmondCore is the heart of AlmondEngine—a feature-complete, cross-platform, task and component-based entry point system. Built with modern C++20, it is designed for modularity, efficiency, and ease of use in cutting-edge game development and beyond.

## Key Features

### Modern, Singleton-Free C++20 Design
AlmondCore eliminates the need for singleton patterns in favor of a modern, functional C++20 approach. This results in scalable and maintainable code, aligning with best practices for contemporary C++ projects.

### Stateless Scene System
A highly flexible and scalable system where scenes are processed by independent tasks, rather than being tightly coupled with game logic. This separation ensures better modularity and allows for efficient scene management.

### Thread-Safe, Multithreaded Task Handler
AlmondCore is built for high-performance multithreading:
- **Wait-Free Queue**: Handles task scheduling efficiently, reducing latency and overhead in multithreaded environments.
- **Custom Spin Lock**: Inspired by WickedEngine's lock-free queue, further optimized for task management under high contention.
- **Fiber-Based Scheduling (Planned)**: Future versions will include fiber-based threading, enhancing performance further.

### Hands-Free Entry Point System
AlmondCore automates the entry point process. Rather than requiring a manual `int main()` function, the system handles initialization behind the scenes, allowing developers to focus on scene creation and task scheduling.

### Core of AlmondEngine
As the foundation of AlmondEngine, AlmondCore provides the essential features for building a powerful, modular 3D game engine, licensed under Apache 2.0 for flexible, open-source use.

### Advanced Task and Event-Driven Design
The engine combines task scheduling with an event-driven system to provide:
- **Scene System**: Manage multiple scenes in parallel.
- **Task Scheduler**: Dynamically distribute tasks across multiple threads.
- **Event System**: Asynchronous event handling for optimal performance.
- **File I/O**: Efficient asset and data management.

## Getting Started

### Prerequisites
Before you begin, ensure you have the following installed:
- C++20 compatible compiler (e.g., MSVC 2019+, GCC 10+, Clang 10+)
- CMake 3.20+
- (Optional) Vulkan SDK or DirectX SDK, depending on the rendering backend

### Building AlmondCore

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/AlmondCore.git
   cd AlmondCore
```
