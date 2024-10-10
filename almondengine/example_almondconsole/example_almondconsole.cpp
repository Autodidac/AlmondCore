#include "almondcore.h"

/*
struct runit
{
    runit() {
    Engine engine(6); // Create engine with 6 threads

    auto entity1 = std::make_unique<Entity>(1, 0.0f, 0.0f); // Create unique entity
    engine.getScene().addEntity(std::move(entity1)); // Move into the scene

    engine.run(); // Run the engine
    }
}myrunit;
*/

//#include <ComponentManager.h>
//#include <PhysicsSystem2D.h>
//#include <RenderingSystem.h>
//#include <JobSystem.h>

struct runit {
    runit() {
        // Initialize the engine with 6 threads
        Engine engine(6);

        // LOGGING EXAMPLE
        Logger logger("engine_log.txt");
        logger.log("Engine initialized with 6 threads.");

        // SCENE & ENTITY MANAGEMENT EXAMPLE
        auto entity1 = std::make_unique<Entity>(1, 0.0f, 0.0f); // Create entity 1
       // auto entity2 = std::make_unique<Entity>(2, 5.0f, 5.0f); // Create entity 2

        Scene& scene = engine.getScene(); // Get the current scene
        scene.addEntity(std::move(entity1)); // Add entity1
      //  scene.addEntity(std::move(entity2)); // Add entity2
        logger.log("Entities added to the scene.");

        // EVENT SYSTEM EXAMPLE
        MovementEvent moveEntity1(1, 2.0f, 3.0f); // Move entity1 by (2.0, 3.0)
        scene.applyMovementEvent(moveEntity1);
        logger.log("MovementEvent applied to entity 1.");

        // Adding movement event to the EventManager
        EventManager eventManager;
        eventManager.addMovementEvent(std::make_unique<MovementEvent>(moveEntity1));
        logger.log("MovementEvent stored in EventManager.");
/*
        // PHYSICS SYSTEM EXAMPLE
        ComponentManager componentManager;
        PhysicsSystem physicsSystem(componentManager); // Removed JobSystem reference
        physicsSystem.update(0.016f); // Update physics (assuming 60 FPS)
        logger.log("Physics system updated.");

        // RENDERING SYSTEM EXAMPLE
        RenderingSystem renderingSystem(componentManager); // Removed JobSystem reference
        renderingSystem.render(); // Render the scene
        logger.log("Rendering system called.");
*/
        // RUNNING THE ENGINE
        engine.run();
        logger.log("Engine run initiated.");

        // CLEANUP
        scene.clearEntities();
        logger.log("Entities cleared from the scene.");
    }
} myrunit;
