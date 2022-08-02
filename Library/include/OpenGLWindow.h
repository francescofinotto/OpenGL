#pragma once
#include <functional>
namespace MyGL
{

    class OpenGLWindow
    {
    public:
        OpenGLWindow(std::string title);
        virtual ~OpenGLWindow();
        virtual void Setup();
        virtual void Update();
        void Run();

    private:
        typedef void *WindowHandler;
        WindowHandler mWindowHandler;
    };

} // namespace MyGL