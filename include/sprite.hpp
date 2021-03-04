#pragma once

#include "quad.hpp"
#include "shader.hpp"
#include "texture.hpp"

namespace RGLA {
    template<class Quad>
    class SpriteBase : public Quad {
    public:
        SpriteBase() : SpriteBase(nullptr) {}
        SpriteBase(
            std::shared_ptr<Texture> texture,
            std::shared_ptr<ShaderProgram> shader = nullptr,
            Vec2 position = {0.0f, 0.0f},
            Vec2 size = {1.0f, 1.0f}
        )   :  Quad(texture, position, size)
            , _shader(shader)
        {}

        void Render() const {
            if (_shader) {
                _shader->SetFloat("brightness", _brightness);
                _shader->SetFloat("opaque", _opaque);
                Quad::Render(*_shader);
            }
        }

        void SetShader(std::shared_ptr<ShaderProgram> shader) {
            _shader = shader;
        }

        float GetBrightness() const {
            return _brightness;
        }
        float GetOpaque() const {
            return _opaque;
        }
        void SetBrightness(float brightness) {
            _brightness = Clamp(brightness, 0.0f, 1.0f);
        }
        void SetOpaque(float opaque) {
            _opaque = Clamp(opaque, 0.0f, 1.0f);
        }

        void SetFilteringMode(TextureFilter filter) {
            Quad::_texture->SetFilteringMode(filter);
        }

        TextureFilter GetFilteringMode() const {
            return Quad::_texture->GetFilteringMode();
        }

    private:
        float _brightness = 1.0f;
        float _opaque = 1.0f;

        std::shared_ptr<ShaderProgram> _shader;
    };

    using Sprite = SpriteBase<TexturedQuad>;
    using DynamicSprite = SpriteBase<TexturedQuadDynamic>;
}
