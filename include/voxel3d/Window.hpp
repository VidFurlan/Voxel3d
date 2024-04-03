#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

class Window {
    public:
        const unsigned int SCR_WIDTH;
        const unsigned int SCR_HEIGHT;

        static float lastX;
        static float lastY;
        static bool firstMouse;

        // Open window
        Window();
        Window(unsigned int width, unsigned int height);

        // GLFW input function callbacks
        static void framebufferSizeCallback(GLFWwindow *window, int width, int height);
        static void mouseCallback(GLFWwindow *window, double xpos, double ypos);
        static void scrollCallback(GLFWwindow *window, double xoffset, double yoffset);
        static void processInput(GLFWwindow *window);

    private:
        void openWindow();
};

#endif
