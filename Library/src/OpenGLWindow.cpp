#include "../include/OpenGLWindow.h"
#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <stdexcept>
#include "glm/vec3.hpp"

namespace MyGL
{
    OpenGLWindow::OpenGLWindow(std::string title)
    {
        if (!glfwInit())
            throw std::runtime_error("Cannot init GLFW");

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

        mWindowHandler = glfwCreateWindow(640, 480, title.c_str(), NULL, NULL);

        if (nullptr == mWindowHandler)
            throw std::runtime_error("Cannot create GLFW Window");

        glfwMakeContextCurrent(static_cast<GLFWwindow *>(mWindowHandler));

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            throw std::runtime_error("Cannot load opengl functions");
        Setup();
    }

    OpenGLWindow::~OpenGLWindow()
    {
        glfwDestroyWindow(static_cast<GLFWwindow *>(mWindowHandler));
    }
    void OpenGLWindow::Run()
    {
        isRunning= true;
        while (!glfwWindowShouldClose(static_cast<GLFWwindow *>(mWindowHandler)))
        {
            glfwMakeContextCurrent(static_cast<GLFWwindow *>(mWindowHandler));
            Update();
            
            glfwSwapBuffers(static_cast<GLFWwindow *>(mWindowHandler));
            glfwPollEvents();
        }
    }
    void OpenGLWindow::Setup(){}
    void OpenGLWindow::Update(){}
} // namespace MyGL