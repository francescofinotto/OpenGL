cmake_minimum_required(VERSION 3.0.0)
project(OpenGLLib VERSION 0.1.0)
file(GLOB LibFiles src/*.cpp)

add_library(${PROJECT_NAME} STATIC ${LibFiles})

target_include_directories(${PROJECT_NAME} PUBLIC include)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)