#include "../include/Triangle.h"
#include "../include/glm/glm.hpp"

namespace MyGL::Shapes
{
    Triangle::Triangle() : vertices{3}
    {
        vertices[0].position = glm::vec3(-0.5f, -0.5f, 0.0f);
        vertices[1].position = glm::vec3(0.5f, -0.5f, 0.0f);
        vertices[2].position = glm::vec3(0.0f, 0.5f, 0.0f);
    }

    Triangle::~Triangle()
    {
    }

    MyGL::Buffer<Vertex> &Triangle::GetBuffer()
    {
        return vertices;
    }
} // namespace MyGL::Shapes