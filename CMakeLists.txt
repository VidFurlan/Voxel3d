cmake_minimum_required(VERSION 3.10)

project(Voxel3d)

set(CMAKE_CXX_STANDARD 11)

# Find and include 
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

# Source files
set(SOURCES
    src/main.cpp
    src/loadShader.cpp
    src/shader.hpp
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link GLEW and GLFW libraries
target_link_libraries(${PROJECT_NAME} PRIVATE GLEW::GLEW glfw)

# Link the OpenGL library explicitly
target_link_libraries(${PROJECT_NAME} PRIVATE -lGL)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE ${GLEW_INCLUDE_DIRS})

# Specify the version of OpenGL you want to use (optional)
target_compile_definitions(${PROJECT_NAME} PRIVATE -DGLM_ENABLE_EXPERIMENTAL)
