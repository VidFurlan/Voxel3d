/*#include <iomanip>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/fwd.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.hpp"
#include "Camera.hpp"
#include "FileGetter.hpp"
#include "FastNoiseGenerator.hpp"

void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
void MouseCallback(GLFWwindow* window, double xpos, double ypos);
void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
void ProcessInput(GLFWwindow *window);

// Settings
const unsigned int SCR_WIDTH = 1600;
const unsigned int SCR_HEIGHT = 900;

FileGetter file_getter("../");

// Camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// Time
float deltaTime = 0.0f;
float lastFrame = 0.0f;

*/

#include "World.hpp"

int main() {
    World world;

    /*
    fng::NoiseMap<float> map1(10, 15, 0.5);
    fng::NoiseMap<float> map2(15, 10, 0.2);
    fng::NoiseMap<float> addMap = map1 + map2;
    
    for (int i = 0; i < addMap.mapWidth(); i++) {
        for (int j = 0; j < addMap.mapHeight(); j++) 
            std::cout << std::setw(4) << addMap[i][j];
        std::cout << std::endl;           
    }



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
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);
    glfwSetCursorPosCallback(window, MouseCallback);
    glfwSetScrollCallback(window, ScrollCallback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Glad - init
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    

    Shader ourShader(file_getter.GetFilePath("shaders/vertex.glsl").c_str(), file_getter.GetFilePath("shaders/fragment.glsl").c_str());

    float vertices[] = {
        -0.5f, -0.5f, -0.5f,      0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,      1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,      1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,      1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,      0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,      0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,      0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,      1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,      1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,      1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,      0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,      0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,      1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,      1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,      0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,      0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,      0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,      1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,      1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,      1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,      0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,      0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,      0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,      1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,      0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,      1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,      1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,      1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,      0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,      0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,      0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,      1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,      1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,      1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,      0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,      0.0f, 1.0f
    };

    glm::vec3 cubePositions[100*100];

    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            cubePositions[i*100+j] = glm::vec3((float)i, 0.0f, (float)j);



    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Load and create a texture 
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    // Texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Load image (create texture and generate mipmaps)
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load(file_getter.GetFilePath("textures/cube.png").c_str(), &width, &height, &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        std::cout << "Failed to load texture" << std::endl;
    }

    stbi_image_free(data);

    ourShader.use(); 
    ourShader.setInt("primary_texture", 2340);

    // Draw wireframe polygons 
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window)) {
        // Per frame update
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Input
        ProcessInput(window);

        // Clear
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Bind textures
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);

        // Use shader
        ourShader.use();

        // pass projection matrix to shader (note that in this case it could change every frame)
        glm::mat4 projection = glm::perspective(glm::radians(camera.zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        ourShader.setMat4("projection", projection);

        // camera/view transformation
        glm::mat4 view = camera.getViewMatrix();
        ourShader.setMat4("view", view);

        // render boxes
        glBindVertexArray(VAO);
        for (unsigned int i = 0; i < 100*100; i++)
        {
            // calculate the model matrix for each object and pass it to shader before drawing
            glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
            model = glm::translate(model, cubePositions[i]);
            float angle = 0.0f;//20.0f * i;
            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
            ourShader.setMat4("model", model);

            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        // GLFW - buffer swap and IO pool events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Deallocate resources after done
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return 0;
    */
}

/*
void ProcessInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.processKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.processKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.processKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.processKeyboard(RIGHT, deltaTime);
}

void MouseCallback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; 

    lastX = xpos;
    lastY = ypos;

    camera.processMouseMovement(xoffset, yoffset);
}

void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.processMouseScroll(static_cast<float>(yoffset));
}

// Handle window resizing using GLFW
void FramebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
*/
