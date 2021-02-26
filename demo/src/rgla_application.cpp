#include <rgla_application.hpp>
#include <quad.hpp>

#include <iostream>
#include <memory>
#include <cmath>

namespace RGLA {
    RGLAApplication::RGLAApplication()
        : Application(800, 600, "RGLA Demo")
    {
        _window->SetClearColor({0.2f, 0.3f, 0.3f, 1.0f});
        _shader = std::make_shared<ShaderProgram>("shaders/basic.vs", "shaders/basic.fs");
        _texture = std::make_shared<FileTexture>("res/container.jpg");
        _inMemoryTexture = std::make_shared<InMemoryTexture>(100, 100, 4);
        for (int x = 25; x <= 75; x++) {
            for (int y = 25; y <= 75; y++) {
                _inMemoryTexture->SetPixel(x, y, 0xFFFFFFFF);
            }
        }

        _sprite = std::make_unique<Sprite>(_texture, _shader, Vec2{-0.5f, -0.5f});
        _sprite2 = std::make_unique<Sprite>(_inMemoryTexture, _shader, Vec2{-0.2f, -0.2f});
        SwitchBlending(true);
    }

    RGLAApplication::~RGLAApplication() {
    }

    bool RGLAApplication::ProcessFrame() {
        float time = glfwGetTime();
        _window->ProcessInput();

        _window->ClearWindow();

        _sprite->SetOpaque((sin(time) / 2.0f) + 0.5f);
        _sprite->Render();
        _sprite2->SetOpaque((sin(time + 3.14f) / 2.0f) + 0.5f);
        _sprite2->Render();

        _window->SwapBuffers();
        return _window->ShouldBeClosed();
    }
}
