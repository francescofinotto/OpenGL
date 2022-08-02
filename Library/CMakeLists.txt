cmake_minimum_required(VERSION 3.0.0)
project(OpenGLLib VERSION 0.1.0)
file(GLOB LibFiles src/*.cpp src/*.c)

add_library(${PROJECT_NAME} STATIC ${LibFiles})

target_include_directories(${PROJECT_NAME} PUBLIC include/ include/glad/ include/GLFW/ include/glm/ include/KHR/)

target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/lib/glfw/glfw3dll.lib)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

set(CMAKE_INSTALL_PREFIX ${RUNTIME_OUTPUT_DIRECTORY})
