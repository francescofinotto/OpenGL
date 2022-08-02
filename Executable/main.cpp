#include <iostream>
#include "OpenGLWindow.h"
#include "Triangle.h"
#include <stdexcept>

class MyGLWindow : public MyGL::OpenGLWindow
{
public:
    MyGLWindow() : OpenGLWindow("My OpenGL Window"){};
    ~MyGLWindow() = default;
    virtual void Setup() override
    {
        
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
