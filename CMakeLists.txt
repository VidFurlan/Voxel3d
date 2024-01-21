cmake_minimum_required(VERSION 3.12)
project(Voxel3d)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenGL REQUIRED)

add_library(glad src/glad.c)
set(LIBS ${LIBS} glad)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/voxel3d)

# add_subdirectory(lib)

file(GLOB PROJECT_HEADERS ${CMAKE_SOURCE_DIR}/include/voxel3d/*.h)

set(SOURCES
    src/main.cpp
    src/Shader.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE glad glfw ${OPENGL_LIBRARIES})

file(COPY shaders DESTINATION ${CMAKE_BINARY_DIR})
file(COPY textures DESTINATION ${CMAKE_BINARY_DIR})
