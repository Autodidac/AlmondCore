
# AlmondCore
AlmondCore is the heart of AlmondEngine—a feature-complete, cross-platform, task and component-based entry point system. It offers built-in stateless scene management designed for modularity, efficiency, and user-friendliness, tailored for modern C++20 projects.

## Key Features
Modern, Singleton-Free C++20 Design
AlmondCore eliminates traditional singleton patterns in favor of a more functional, modern C++20 approach. This results in cleaner, more scalable code, adhering to the best practices of contemporary C++ development.

### Stateless Scene System
A highly flexible and scalable system where scenes are processed by independent tasks, rather than being tightly coupled to game logic. This architecture improves separation of concerns, allowing for more modular scene management.

### Thread-Safe, Multithreaded Task Handler
AlmondCore leverages cutting-edge multithreading technology:

Fiber Technology: Inspired by systems like Naughty Dog's game engine (see more).
Custom Spin Lock: Similar to WickedEngine’s lock-free queue with custom spin-lock waits, but further optimized.
Wait-Free Queue: AlmondCore currently implements a wait-free queue for efficient, thread-safe task scheduling, moving towards fiber-based threading for future versions.
Wait-Free, High-Performance Thread Queue
Built to handle high-contention environments, AlmondCore’s wait-free thread queue minimizes latency and overhead, ensuring peak performance in multithreaded applications—particularly useful in high-demand scenarios. Ongoing testing explores transitioning to fiber-based scheduling to push performance even further.

### Hands-Free Entry Point System
No need for the traditional int main() entry point. AlmondCore provides a built-in entry system that handles initialization for you. Simply include the library and focus on creating scenes and tasks—the system takes care of the rest.

### Core of AlmondEngine
AlmondCore serves as the foundation of AlmondEngine, a modular 3D game engine that is free and open-source, licensed under Apache 2.0. This makes it suitable for both hobbyists and professional developers seeking a robust engine for their projects.

### Advanced Multithreading, Task-and-Event Driven Hybrid Engine Design
AlmondCore is designed for extensibility with a flexible Entity Component System (ECS). It provides powerful, agent-like behavior for complex systems, including (But NOT limited to) game development. 

#### Core components include:
- Scene System: Manage multiple scenes with ease.
- Task Scheduler: Efficiently distribute tasks across multiple threads.
- Event System: Process events asynchronously for better performance.
- Logging and Timing: Built-in utilities for profiling and debugging.
- File I/O Operations: Handle assets and data efficiently.
- High Efficiency & Minimalist Design
- While feature-rich, AlmondCore remains streamlined to ensure high performance, even in demanding environments. Its minimalist, functional design makes it ideal for developers focused on scalability without unnecessary complexity. The open-source, commercial-friendly Apache 2.0 license allows for flexible customization and usage in both personal and professional projects.

