#include "World.hpp"

World::World() {
    playerCamera = Camera(glm::vec3(0.0f, 0.0f, 3.0f));
    deltaTime = 0.0f;
    lastFrame = 0.0f;
}
