#pragma once

#include "mesh.hpp"
#include "shader.hpp"

namespace RGLA {
    class Quad {
    public:
        Quad(Vec2 position, Vec2 size)
            : _mesh(
                std::vector<Vertex>({
                    {{1.0f, 1.0f, 0.0f}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}, {0.0f, 0.0f}},
                    {{1.0f, 0.0f, 0.0f}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}, {0.0f, 0.0f}},
                    {{0.0f, 0.0f, 0.0f}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}, {0.0f, 0.0f}},
                    {{0.0f, 1.0f, 0.0f}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}, {0.0f, 0.0f}}
                }),
                std::vector<uint>({0, 1, 3, 1, 2, 3})
            )
            , _position(position)
            , _size(size)
        {}

        Quad(Vec2 position)
            : Quad(position, Vec2{1.0f, 1.0f})
        {}

        Quad()
            : Quad(Vec2{0.0f, 0.0f})
        {}

        void Render(ShaderProgram& shader) const {
            PrepareRender(shader);
            _mesh.Render();
        }

    protected:
        virtual void PrepareRender(ShaderProgram& shader) const {
            TransformMatrix transform;
            transform.Scale(Vec3{_size.x, _size.y, 1.0f});
            transform.Translate(Vec3{_position.x, _position.y, 1.0f});
            shader.SetMat4("transform", transform);
        }

        Mesh _mesh;
        Vec2 _position;
        Vec2 _size;
    };

    class TexturedQuad : public Quad {
    public:
        TexturedQuad(std::shared_ptr<Texture> texture, Vec2 position, Vec2 size)
            : Quad(position, size)
            , _texture(texture)
        {}

        TexturedQuad(std::shared_ptr<Texture> texture, Vec2 position)
            : TexturedQuad(texture, position, Vec2{1.0f, 1.0f})
        {}

        TexturedQuad(std::shared_ptr<Texture> texture)
            : TexturedQuad(texture, Vec2{0.0f, 0.0f})
        {}

    protected:
        void PrepareRender(ShaderProgram& shader) const override {
            Quad::PrepareRender(shader);
            _texture->Use(0);
            shader.SetInt("tex", 0);
        }

        std::shared_ptr<Texture> _texture;
    };

    // TODO: Reload texture every frame
    class TexturedQuadDynamic : public TexturedQuad {
    public:
        using TexturedQuad::TexturedQuad;
    };
}
