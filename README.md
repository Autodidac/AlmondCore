# AlmondCore
The heart of AlmondEngine, AlmondCore is a feature-complete, cross-platform task and component-based entry point system. It includes built-in stateless scene management designed to be modular, efficient, and user-friendly for modern C++20 projects.

### Advanced Features
Singleton-free, Modern C++20 Design
AlmondCore avoids traditional singleton patterns in favor of a more functional and modern approach to C++20, allowing cleaner, more scalable code.

#### Stateless Scene System
A system designed for flexibility and scalability, where scenes are processed by tasks instead of being tightly coupled with game logic, offering better separation of concerns.

#### Thread-Safe, Multithreaded Task Handler
Implimenting Fiber Technology - Naughty Dog Engine - https://www.youtube.com/watch?v=HIVBhKj7gQU
WickedEngine uses Lock-Free Queue with Custom Spin Lock Thread Waits - Performant but we can do better! AlmondCore Currently Impliments a Custom Written Wait-Free Queue with Thread-Safe Task Scheduler (Moving beyond that to Thread-Fibers!)
Execute tasks efficiently across multiple threads without worrying about thread safety, ensuring smooth performance in multi-core environments.

#### Wait-Free, Thread Queue
Achieve maximum efficiency with a wait-free thread queue, ideal for handling high-contention environments with minimal latency and overhead. (Testing indicates this would be most performant under maximum-contention cases (currently investigating Thread-Fibers))

#### Hands-Free Entry Point System
Say goodbye to the traditional int main()—AlmondCore provides a built-in entry point, allowing you to focus on building scenes and processing tasks. Simply include the library, and the entry system handles the rest.

#### Foundation of AlmondEngine
AlmondCore serves as the backbone of AlmondEngine, a modular 3D graphics and game engine designed to be free and open-source under the (No Trademark Infringement and State Your Changes) Apache 2.0 license.

#### Multithreaded Task Oriented, Event Centric, Component-Pattern Based Custom Hybrid Engine Design
Designed for extensibility, AlmondCore integrates a flexible Entity Component System (ECS). This allows for powerful agent-like behavior in C++ programs, providing more than enough functionality for game development and other complex systems.
Along with Component attachable Entities is the SceneSystem, Task Scheduler, EventSystem, Logging, Timing, and File-I/O operations and common utilities AlmondCore sports State-of-the-Art Technologies for Performance AND EFFICIANCY in an Ever Demanding Game Development Industry.

#### Minimalist, Functional Program Design
AlmondCore emphasizes high efficiency and scalability without compromising user-friendliness. While the system may seem feature-rich, it is streamlined to ensure it operates efficiently even in demanding environments. The open-source, commercial-friendly licensing (Apache 2.0) allows developers to freely tailor the engine to their needs.

