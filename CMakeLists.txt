cmake_minimum_required(VERSION 3.12)
project(Voxel3d)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

add_library(glad src/glad.c)
set(LIBS ${LIBS} glad)

include(FetchContent)
FetchContent_Declare(
	glm
	GIT_REPOSITORY	https://github.com/g-truc/glm.git
	GIT_TAG 	bf71a834948186f4097caa076cd2663c69a10e1e #refs/tags/1.0.1
)
FetchContent_MakeAvailable(glm)

# Header includes
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/voxel3d)

file(GLOB PROJECT_HEADERS 
    ${CMAKE_SOURCE_DIR}/include/voxel3d/*.h
    ${CMAKE_SOURCE_DIR}/include/voxel3d/*.hpp
)

set(SOURCES
    src/main.cpp
    src/World/World.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE glad glfw glm::glm ${OPENGL_LIBRARIES})

file(COPY shaders DESTINATION ${CMAKE_BINARY_DIR})
file(COPY textures DESTINATION ${CMAKE_BINARY_DIR})
