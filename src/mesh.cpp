#include <mesh.hpp>

namespace RGLA {
    Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<uint>& indices)
        : _vertices(vertices)
        , _indices(indices)
    {
        glGenVertexArrays(1, &_vaoId);
        glGenBuffers(1, &_posVboId);
        glGenBuffers(1, &_eboId);

        glBindVertexArray(_vaoId);

        glBindBuffer(GL_ARRAY_BUFFER, _posVboId);
        glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * _vertices.size(), _vertices.data(), GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _eboId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint) * _indices.size(), indices.data(), GL_STATIC_DRAW);

        // Position
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
        glEnableVertexAttribArray(0);

        // Color
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
        glEnableVertexAttribArray(1);

        // texCoord
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoord));
        glEnableVertexAttribArray(2);
    }

    Mesh::~Mesh() {
        glDeleteBuffers(1, &_eboId);
        glDeleteBuffers(1, &_posVboId);
        glDeleteVertexArrays(1, &_vaoId);
    }

    void Mesh::Render() const {
        glBindVertexArray(_vaoId);
        glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0);
    }
}
