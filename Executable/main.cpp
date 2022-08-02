#include <iostream>
#include "OpenGLWindow.h"
#include "Mesh.h"
#include "Shader.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

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

        program = std::make_shared<MyGL::ShaderProgram>(std::move(vert),std::move(frag));
        triangle = std::make_shared<MyGL::Mesh::Triangle>();

        renderer = MyGL::Mesh::Renderer(std::dynamic_pointer_cast<MyGL::Mesh::Mesh>(triangle),program);
    }
    virtual void Update() override
    {
        renderer.Render();
    }

private:
    std::shared_ptr<MyGL::Mesh::Triangle> triangle;
    std::shared_ptr<MyGL::ShaderProgram> program;
    MyGL::Mesh::Renderer renderer;
    
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
