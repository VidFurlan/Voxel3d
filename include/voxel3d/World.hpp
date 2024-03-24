#ifndef WORLD_H
#define WORLD_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/fwd.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Camera.hpp"
#include "ChunkLoader.hpp"
#include "Shader.hpp"
#include "FileGetter.hpp"
#include "InputGetter.hpp"

class World {
    private:
        // General
        FileGetter fileGetter = FileGetter("../");
        InputGetter inputGetter = InputGetter();
        GLFWwindow* window;

        // Shader and textures
        Shader voxelShader = Shader(fileGetter.GetFilePath("shaders/vertex.glsl").c_str(), fileGetter.GetFilePath("shaders/fragment.glsl").c_str());
        unsigned int texture;

        // Rendering
        unsigned int VBO, VAO;

        // Game
        ChunkLoader chunkLoader = ChunkLoader();

    public:
        // Settings
        const unsigned int SCR_WIDTH = 1600;
        const unsigned int SCR_HEIGHT = 900;

        // Camera
        Camera camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f));
        float lastX = SCR_WIDTH / 2.0f;
        float lastY = SCR_HEIGHT / 2.0f;
        bool firstMouse = true;

        // Time
        float deltaTime = 0.0f;
        float lastFrame = 0.0f;

        World();
        int initWindow();
        int GameLoop();
};

#endif
