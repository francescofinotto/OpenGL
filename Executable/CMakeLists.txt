cmake_minimum_required(VERSION 3.0.0)
project(OpenGLExe VERSION 0.1.0)


add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} OpenGLLib)
# set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

file(COPY lib/glfw/glfw3.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug/)
