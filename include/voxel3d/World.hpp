#ifndef WORLD_H
#define WORLD_H

#include <string>

#include <glm/glm.hpp>

#include "Camera.hpp"
#include "Window.hpp"

class World {
    public:
        static Camera playerCamera;
        static Window gameWindow;

        static float deltaTime;
        static float lastFrame;

        // World generation/loading method
        World();
        World(int seed);            // Todo
        World(std::string file);    // Todo
                                    
    private:
        void initWorld();
};

#endif
