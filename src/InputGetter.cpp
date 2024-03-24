#include "InputGetter.hpp"

InputGetter::InputGetter(World *worldRef) {
    world = worldRef;
}

void InputGetter::ProcessInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        world->camera.processKeyboard(FORWARD, world->deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        world->camera.processKeyboard(BACKWARD, world->deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        world->camera.processKeyboard(LEFT, world->deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        world->camera.processKeyboard(RIGHT, world->deltaTime);
}

void InputGetter::MouseCallback(GLFWwindow* window, double xposIn, double yposIn) {
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (world->firstMouse)
    {
        world->lastX = xpos;
        world->lastY = ypos;
        world->firstMouse = false;
    }

    float xoffset = xpos - world->lastX;
    float yoffset = world->lastY - ypos; 

    world->lastX = xpos;
    world->lastY = ypos;

    world->camera.processMouseMovement(xoffset, yoffset);
}

void InputGetter::ScrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
    world->camera.processMouseScroll(static_cast<float>(yoffset));
}

void InputGetter::FramebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
