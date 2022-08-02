#include "../include/Shader.h"
#include "../include/glad/glad.h"
#include <stdexcept>
#include <iostream>

namespace MyGL
{

    bool CompilationHasErrorAndLog(unsigned int shaderPtr)
    {
        int result;
        glGetShaderiv(shaderPtr, GL_COMPILE_STATUS, &result);
        if (GL_FALSE == result)
        {
            int logLenght;
            glGetShaderiv(shaderPtr, GL_INFO_LOG_LENGTH, &logLenght);
            if (logLenght > 0)
            {
                unsigned int written;
                unsigned char log [1024];
                glGetShaderInfoLog(shaderPtr, logLenght, (GLsizei *)&written, (GLchar *)log);
                std::cerr << log << std::endl;
            }
            return true;
        }
        return false;
    }
    bool LinkingHasErrorAndLog(unsigned int shaderPtr)
    {
        int result;
        glGetShaderiv(shaderPtr, GL_LINK_STATUS, &result);
        if (GL_FALSE == result)
        {
            int logLenght;
            glGetShaderiv(shaderPtr, GL_INFO_LOG_LENGTH, &logLenght);
            if (logLenght > 0)
            {
                unsigned int written;
                unsigned char *log;
                glGetShaderInfoLog(shaderPtr, logLenght, (GLsizei *)written, (GLchar *)log);
                std::cerr << *log << std::endl;
            }
            return true;
        }
        return false;
    }
    unsigned int CreateVertexShader(std::string shaderText)
    {
        unsigned int shaderPtr = glCreateShader(GL_VERTEX_SHADER);
        auto shaderCString = shaderText.c_str();
        glShaderSource(shaderPtr, 1, &shaderCString, NULL);
        glCompileShader(shaderPtr);
        if (CompilationHasErrorAndLog(shaderPtr))
            throw std::runtime_error("Error creating Fragment Shader");
        return shaderPtr;
    }

    unsigned int CreateFragmentShader(std::string shaderText)
    {
        unsigned int shaderPtr = glCreateShader(GL_FRAGMENT_SHADER);
        auto shaderCString = shaderText.c_str();
        glShaderSource(shaderPtr, 1, &shaderCString, NULL);
        glCompileShader(shaderPtr);
        if (CompilationHasErrorAndLog(shaderPtr))
            throw std::runtime_error("Error creating Fragment Shader");
        return shaderPtr;
    }

    Shader::Shader(std::string shaderText, SHADER_TYPE type)
    {
        if (type == Shader::SHADER_TYPE::VERTEXT)
            shaderPtr = CreateVertexShader(shaderText);
        else if (type == Shader::SHADER_TYPE::FRAGMENT)
            shaderPtr = CreateVertexShader(shaderText);
    }

    Shader::~Shader()
    {
        glDeleteShader(shaderPtr);
    }
    Shader::Shader(Shader &&other)
    {
        if (this == &other)
            return;
        shaderPtr = other.shaderPtr;
        other.shaderPtr = 0;
    }
    Shader &Shader::operator=(Shader &&other)
    {
        if (this == &other)
            return *this;
        shaderPtr = other.shaderPtr;
        other.shaderPtr = 0;
        return *this;
    }
    unsigned int Shader::GetShaderPtr()
    {
        return shaderPtr;
    }

    ShaderProgram::ShaderProgram(Shader vertex, Shader fragment)
    {
        shaderPtr = glCreateProgram();
        glAttachShader(shaderPtr, vertex.GetShaderPtr());
        glAttachShader(shaderPtr, fragment.GetShaderPtr());
        glLinkProgram(shaderPtr);
        glDetachShader(shaderPtr, vertex.GetShaderPtr());
        glDetachShader(shaderPtr, fragment.GetShaderPtr());
        if (LinkingHasErrorAndLog(shaderPtr))
            throw std::runtime_error("Error linking shader program");
    }
    ShaderProgram::ShaderProgram(ShaderProgram &&other)
    {
        if (this == &other)
            return;
        shaderPtr = other.shaderPtr;
        other.shaderPtr = 0;
    }
    ShaderProgram &ShaderProgram::operator=(ShaderProgram &&other)
    {
        if (this == &other)
            return *this;
        shaderPtr = other.shaderPtr;
        other.shaderPtr = 0;
        return *this;
    }
    ShaderProgram::~ShaderProgram()
    {
        glDeleteProgram(shaderPtr);
    }

    void ShaderProgram::Bind()
    {
        glUseProgram(shaderPtr);
    }
} // namespace MyGL