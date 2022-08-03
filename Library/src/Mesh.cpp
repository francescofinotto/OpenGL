#include "../include/Mesh.h"
#include "../include/glm/glm.hpp"
#include "../include/glad/glad.h"
#include "../include/GLUtils.h"
#include <iostream>

namespace MyGL::Mesh
{
    Mesh::Mesh(size_t count) : vertices{count} {}

    Triangle::Triangle() : Mesh(3)
    {
        vertices[0].position = glm::vec3(-0.5f, -0.5f, 0.0f);
        vertices[1].position = glm::vec3(0.5f, -0.5f, 0.0f);
        vertices[2].position = glm::vec3(-0.0f, 0.5f, 0.0f);
    }

    Triangle::~Triangle()
    {
    }

    MyGL::Buffer<Vertex> &Triangle::GetBuffer()
    {
        return vertices;
    }

    Renderer::Renderer(std::shared_ptr<Mesh> mesh, std::shared_ptr<ShaderProgram> shaderProgram)
        : mesh(mesh), shader(shaderProgram)
    {
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
        unsigned int vbo;
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        float positions = float[9]{
            mesh->GetBuffer()[0].position.x,
            mesh->GetBuffer()[0].position.y,
            mesh->GetBuffer()[0].position.z,

            mesh->GetBuffer()[1].position.x,
            mesh->GetBuffer()[1].position.y,
            mesh->GetBuffer()[1].position.z,

            mesh->GetBuffer()[2].position.x,
            mesh->GetBuffer()[2].position.y,
            mesh->GetBuffer()[2].position.z,
        };
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 9, &positions, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, 0, sizeof(float)*3, 0);
    }
    Renderer::~Renderer()
    {
        glDeleteBuffers(1, &vao);
    }
    void Renderer::Render()
    {
        MyGL::Utils::DoAndLogError([&](){
                shader->Bind();
                glBindVertexArray(vao);
                glDrawArrays(GL_TRIANGLES, 0, mesh->GetBuffer().size());
        });
    }
    Renderer::Renderer(Renderer &&other)
    {
        if (this == &other)
            return;
        mesh = std::move(other.mesh);
        shader = std::move(other.shader);
        vao = other.vao;
        other.vao = 0;
    }
    Renderer &Renderer::operator=(Renderer &&other)
    {
        if (this == &other)
            return *this;
        mesh = std::move(other.mesh);
        shader = std::move(other.shader);
        vao = other.vao;
        other.vao = 0;
        return *this;
    }
} // namespace MyGL::Shapes