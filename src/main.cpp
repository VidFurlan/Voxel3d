#include "World.hpp"

World *world = new World();

int main() {
    world->initWindow();
    world->GameLoop();

    return 0;
}
