cmake_minimum_required(VERSION 3.0.0)
project(OpenGLExe VERSION 0.1.0)


add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} OpenGLLib)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

file(COPY lib/glfw/glfw3.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug/)
file(GLOB SHADERS Shaders/*.vert Shaders/*.frag )
file(COPY ${SHADERS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug/Shaders/)

