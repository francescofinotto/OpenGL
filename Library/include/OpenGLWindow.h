#pragma once

class OpenGLWindow
{
public:
    OpenGLWindow();
    virtual ~OpenGLWindow();
    virtual void Run();
private:
    typedef void* WindowHandler;
    WindowHandler mWindowHandler;
};

