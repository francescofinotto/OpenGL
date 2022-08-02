#pragma once
#include "Buffer.h"
#include "Vertex.h"

namespace MyGL::Shapes
{

    class Triangle
    {
    public:
        Triangle();
        ~Triangle();
        MyGL::Buffer<MyGL::Vertex> &GetBuffer();

    private:
        MyGL::Buffer<MyGL::Vertex> vertices;
    };

} // namespace MyGL::Shapes