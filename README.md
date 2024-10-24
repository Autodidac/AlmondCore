<img align="left" src="images/1.jpg" width="70px"/>

# Almond Core



## Almond Core - The Heart of the AlmondEngine is a x64 Cross-platform OS Entry-Point System with Data-Oriented, Functional/OOP Hybrid, Task and Event Driven Component based Architecture with built-in Stateless Scene Management, ECS, and more.

Built with contemporary design principles and using C++20, it is designed for modularity, efficiency, and ease of use on current OS hardware for bleeding-edge software development and beyond. For Graphics Rendering Capabilities see AlmondEngine or AlmondShell. AlmondCore is a Modern Software Development Suite which aims to be as minimal as possible and also features a header only mostly functional programming design to reduce overhead.

<img align="left" src="images/gpt.jpg" width="70px"/>GPT-4




---
---
## AlmondEngine 'Core' Overview
The AlmondEngine is a modern, scalable, and data-oriented game engine designed to support efficient game development in 2024. It incorporates a variety of subsystems that work together to provide a powerful and flexible framework for creating games. Below are the key components and features of the engine:

1. Entity Component System (ECS)
Core Architecture: The ECS is designed to manage entities and their associated components, enabling a data-oriented approach that enhances performance and cache efficiency.
Dynamic Component Management: It allows for the addition, retrieval, and removal of components at runtime, facilitating flexible game object behavior.
2. Job System
Lock-Free and Wait-Free Queues: The job system enables concurrent task processing without locking, significantly reducing the risk of deadlocks and contention between threads.
Dedicated Threads for Systems: Systems can run on dedicated threads, allowing for more efficient processing of game logic, rendering, physics, and other tasks. This separation of concerns improves overall performance.
3. Event Management
Event Manager: This subsystem handles events and state changes within the game, supporting an event-driven architecture that decouples components from one another.
Automated Event Handling: Events can be queued, and systems can respond to these events as they occur, allowing for dynamic game behavior without tight coupling.
4. Advanced Task and Event-Driven Data-Oriented (DOD) + OOP + Functional Programming Custom Hybrid Design
This thing is absolute overkill to build a calculator with, but it would make it a lot easier, or a scientific physics simulation, or a game engine, leveraged but a functional header only data oriented design.
Component Storage: Components are stored in a way that optimizes data locality, improving cache performance and reducing memory access latency.
Separation of Data and Logic: This design principle ensures that the engine can efficiently manage large quantities of entities and components while maintaining high-performance execution.
6. Modular and Extensible Architecture
Easy Integration: New components, systems, or features can be added to the engine without significant modifications to the existing codebase.
Support for Plugins: The engine is designed to allow third-party developers to create plugins or extensions, enabling a vibrant ecosystem around the engine.
7. Scalable Systems
Multithreading Support: The engine leverages multiple cores effectively by distributing workloads across threads, ensuring that it can scale with the complexity of the game.
Adaptive Resource Management: Resources such as memory, graphics, and audio can be managed dynamically based on the needs of the game, improving performance and efficiency.
8. Input Management
Unified Input System: The engine provides a unified interface for handling input from various sources (keyboard, mouse, gamepad, etc.), allowing for consistent handling of player interactions.
9. Scripting and Behavior Systems
Scripting Support: The engine can integrate scripting languages (like C#, Lua, or Python, Rust, D, Go) to allow designers to write game logic without modifying the core engine code.
Behavior Trees/State Machines: Support for behavior trees or state machines can be incorporated for AI and complex entity behaviors, allowing for flexible design of non-player characters (NPCs).
10. Rendering and Graphics
Renderer Module: The engine includes a rendering subsystem that can leverage modern graphics APIs (like Vulkan or DirectX 12) for high-quality graphics and effects.
Post-Processing Effects: Support for advanced rendering techniques such as post-processing effects, particle systems, and shader management.

#### Conclusion
The AlmondEngine is a sophisticated game engine built on modern principles of software design, focusing on performance, scalability, and flexibility. By combining an ECS with advanced job systems, event management, and a modular architecture, it provides a powerful framework for game developers to create immersive and high-performance games in 2024. Its design is well-suited for the demands of contemporary game development, ensuring that developers can focus on crafting engaging experiences without being bogged down by performance constraints or architectural limitations.

----------------------------------------

## Key Features of AlmondCore



### Modern, Singleton-Free C++20 Design
AlmondCore eliminates the need for singleton patterns in favor of a modern, functional C++20 approach. This results in scalable and maintainable code, aligning with best practices for contemporary C++ projects.



### Stateless Scene System
A highly flexible and scalable system where scenes are processed by independent tasks, rather than being tightly coupled with game logic. This separation ensures better modularity and allows for efficient scene management.



### Thread-Safe, Multithreaded Task Handler
AlmondCore is built for high-performance multithreading:
- **Wait-Free Queue**: Handles task scheduling efficiently, reducing latency and overhead in multithreaded environments.



### Hands-Free Entry Point System
AlmondCore automates the entry point process. Rather than requiring a manual `int main()` function, the system handles initialization behind the scenes, allowing developers to focus on scene creation and task scheduling.



### Core of AlmondEngine
As the foundation of AlmondEngine, AlmondCore provides the essential features for building a powerful, modular 3D game engine, licensed under Apache 2.0 for flexible, open-source use.



### Advanced Task and Event-Driven Data-Oriented (DOD) + OOP + Functional Programming Hybrid Design
The engine combines task scheduling with an event-driven system to provide:
- **Scene System**: Manage multiple scenes in parallel.
- **Task Scheduler**: Dynamically distribute tasks across multiple threads. Thread Pooling, no .lock() Wait Free Queue Using Atomics for Multithreading.
- **Event System**: Asynchronous event handling for optimal performance. Clever Stepping Save System with Compressed Binary Save Caching.
- **Advanced Timing Mechanism**: Feature Complete Internal Timing, Perhaps a First of it's kind Intelligent Design.
- **File I/O**: Efficient asset and data management.

------

## Getting Started Using Almond Core

### Prerequisites
Before you begin, ensure you have the following installed:
- C++20 compatible compiler (e.g., MSVC 2019+, GCC 10+, Clang 10+)
- CMake 3.20+ (Optional) 

### Building AlmondCore

1. **Clone the Repository**:
```bash
   git clone https://github.com/Autodidac/AlmondCore.git
   cd AlmondCore
```
2. **Configure with CMake**:
   Depending on your platform and choice of backend (Vulkan or DirectX):
   
   - For **Vulkan**:
     ```bash
     cmake -S . -B build -D RENDERING_BACKEND=VULKAN
     ```

   - For **DirectX**:
     ```bash
     cmake -S . -B build -D RENDERING_BACKEND=DX12
     ```

   This will generate the appropriate build files for your platform.

3. **Build the Project**:
### Build with CMake

1. **Create a Build Directory**:
```bash
   mkdir build
   cd build
```
##### **Run CMake**:
```bash
cmake ..
```
##### **Build the Project**:
```bash
cmake --build . --config Release
```
##### Run the Examples:
```bash
cd examples
./example_project
```

### License
- AlmondCore is licensed under the Apache 2.0 License. See the LICENSE file for more details.

### Contributing
- Contributions are welcome! Please feel free to submit a pull request or open an issue.

### Getting Help
- If you have any questions or need help, feel free to open an issue on the GitHub repository or reach out to the community.
