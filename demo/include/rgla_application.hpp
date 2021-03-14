#pragma once

#include <application.hpp>
#include <math.hpp>
#include <window.hpp>
#include <mesh.hpp>
#include <shader.hpp>
#include <texture.hpp>
#include <sprite.hpp>
#include <scene.hpp>

#include <vector>
#include <memory>

namespace RGLA {
    class RGLAApplication : public Application {
    public:
        RGLAApplication();
        ~RGLAApplication();

        bool ProcessFrame() override;
        void ProcessInput(KeyCode key, InputKeyStatus status);
    private:
        bool _ShouldExit = false;

        std::shared_ptr<ShaderProgram> _shader;
        std::shared_ptr<Texture> _texture;
        std::shared_ptr<InMemoryTexture> _inMemoryTexture;
        std::shared_ptr<InMemoryTexture> _textureCopy;

        std::shared_ptr<Sprite> _sprite;
        std::shared_ptr<Sprite> _sprite2;
        std::shared_ptr<Sprite> _sprite3;

        std::unique_ptr<Scene> _scene;
    };
}
