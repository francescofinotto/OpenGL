#pragma once
#include "glm/glm.hpp"
namespace MyGL
{

    struct Vertex
    {
        float* position = nullptr;
        ~Vertex(){
            delete[] position;
        }
    };

} // namespace MyGL