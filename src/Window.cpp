#include "Window.hpp"
#include "World.hpp"

Window::Window() : SCR_WIDTH(1600), SCR_HEIGHT(900) {

}

Window::Window(unsigned int width, unsigned int height) : SCR_WIDTH(width), SCR_HEIGHT(height) {

}

void Window::openWindow() {
    lastX = SCR_WIDTH / 2.0f;
    lastY = SCR_HEIGHT / 2.0f;
    firstMouse = true;

    // GLFW - init
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // GLFW - create window
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    glfwSetCursorPosCallback(window, mouseCallback);
    glfwSetScrollCallback(window, scrollCallback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Glad - init
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }    
}

void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        World::playerCamera.processKeyboard(FORWARD, World::deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        World::playerCamera.processKeyboard(BACKWARD, World::deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        World::playerCamera.processKeyboard(LEFT, World::deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        World::playerCamera.processKeyboard(RIGHT, World::deltaTime);
}

void mouseCallback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (Window::firstMouse)
    {
        Window::lastX = xpos;
        Window::lastY = ypos;
        Window::firstMouse = false;
    }

    float xoffset = xpos - Window::lastX;
    float yoffset = Window::lastY - ypos; 

    Window::lastX = xpos;
    Window::lastY = ypos;

    World::playerCamera.processMouseMovement(xoffset, yoffset);
}

void scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    World::playerCamera.processMouseScroll(static_cast<float>(yoffset));
}

// Handle window resizing using GLFW
void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
