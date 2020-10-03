#pragma once

#include "vertex.hpp"

#include <glad/glad.h>

#include <vector>

namespace RGLA {
    class Mesh {
    public:
        Mesh(const std::vector<Vertex>& vertices, const std::vector<uint>& indices);
        virtual ~Mesh();
        void Render() const;
    private:
        uint _vaoId;
        uint _posVboId;
        uint _eboId;
        std::vector<Vertex> _vertices;
        std::vector<uint> _indices;
    };
}
