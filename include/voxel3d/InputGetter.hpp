#ifndef INPUT_GETTER_H
#define INPUT_GETTER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Camera.hpp"

class InputGetter {
    public:
        static World *world;
        static void ProcessInput(GLFWwindow *window);
        static void MouseCallback(GLFWwindow *window, double xposIn, double yposIn);
        static void ScrollCallback(GLFWwindow *window, double xoffset, double yoffset);
        static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
};

#endif
