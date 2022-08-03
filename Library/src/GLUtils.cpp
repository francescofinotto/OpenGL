#include "../include/GLUtils.h"
#include "../include/glad/glad.h"
#include <iostream>

namespace MyGL::Utils
{

    void DoAndLogError(std::function<void(void)> glFunction, std::string message)
    {
        glFunction();
        auto error = glGetError();
        if (error != GL_NO_ERROR)
            std::cout << message << ": " << error << std::endl;
    }
} // namespace MyGL::Utils