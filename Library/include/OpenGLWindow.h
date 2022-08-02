#pragma once
#include <functional>
namespace MyGL
{

    class OpenGLWindow
    {
    public:
        OpenGLWindow();
        virtual ~OpenGLWindow();
        virtual void Run();

    private:
        typedef void *WindowHandler;
        WindowHandler mWindowHandler;
    };

} // namespace MyGL