#include <iostream>
#include "OpenGLWindow.h"
#include <stdexcept>
int main(int, char**) {
    try{
        MyGL::OpenGLWindow window{};

        window.Run();


    }catch(std::exception exc){
        std::cout<<exc.what()<<std::endl;
    }catch(...)
    {
        std::cout<<"Unknow error"<<std::endl;
    }
}
