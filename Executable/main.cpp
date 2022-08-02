#include <iostream>
#include "OpenGLWindow.h"
#include "Triangle.h"
#include "Shader.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>

class MyGLWindow : public MyGL::OpenGLWindow
{
public:
    MyGLWindow() : OpenGLWindow("My OpenGL Window"){};
    ~MyGLWindow() = default;
    virtual void Setup() override
    {
        std::ifstream vertFile{"Shaders/default.vert"};
        std::ifstream fragFile{"Shaders/default.frag"};

        std::stringstream vertStream;
        std::stringstream fragStream;

        vertStream<<vertFile.rdbuf();
        fragStream<<fragFile.rdbuf();
        
        std::string vertText = vertStream.str();
        std::string fragText = fragStream.str();
        
        vertFile.close();
        fragFile.close();

        MyGL::Shader vert(vertText, MyGL::Shader::VERTEXT);
        MyGL::Shader frag(fragText, MyGL::Shader::FRAGMENT);

        MyGL::ShaderProgram program{vert, frag};
        
    }
    virtual void Update() override
    {
    }

private:
    MyGL::Shapes::Triangle triangle;
};

int main(int, char **)
{
    try
    {
        MyGLWindow window{};

        window.Run();
    }
    catch (std::exception exc)
    {
        std::cout << exc.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "Unknow error" << std::endl;
    }
}
