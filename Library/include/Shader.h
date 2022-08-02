#pragma once

#include <string>
namespace MyGL
{
    class Shader
    {
    public:
        enum SHADER_TYPE
        {
            VERTEXT = 0,
            FRAGMENT = 1,
            PIXEL = 1
        };
        Shader(std::string shaderText, SHADER_TYPE type);
        ~Shader();
        unsigned int GetShaderPtr();

    private:
        unsigned int shaderPtr;
    };
    
    class ShaderProgram
    {
    public:
        ShaderProgram(Shader vertex, Shader fragment);
        ~ShaderProgram();
        void Bind();

    private:
        unsigned int shaderPtr;
    };

} // namespace MyGL