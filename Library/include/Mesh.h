#pragma once
#include "Buffer.h"
#include "Vertex.h"
#include "Shader.h"
#include <memory>

namespace MyGL::Mesh
{
    class Mesh
    {

    public:
        Mesh(size_t count);
        virtual ~Mesh() = default;
        virtual MyGL::Buffer<MyGL::Vertex>& GetBuffer() = 0;

    protected:
        MyGL::Buffer<MyGL::Vertex> vertices;
    };

    class Triangle: public Mesh
    {

    public:
        Triangle();
        ~Triangle();
        virtual MyGL::Buffer<MyGL::Vertex> &GetBuffer() override;

    private:
        // MyGL::Buffer<MyGL::Vertex> vertices;
    };

    class Renderer
    {
        public:
            Renderer() = default;
            Renderer(std::shared_ptr<Mesh> mesh,std::shared_ptr<ShaderProgram> shaderProgram);
            Renderer(Renderer &&other);
            Renderer& operator=(Renderer &&other);
            ~Renderer();
            void Render();
        private:
            std::shared_ptr<Mesh> mesh;
            std::shared_ptr<ShaderProgram> shader;
            unsigned int vbo;
    };
    
} // namespace MyGL::Shapes