#include <rgla_application.hpp>
#include <quad.hpp>

#include <iostream>
#include <memory>
#include <cmath>

namespace RGLA {
    RGLAApplication::RGLAApplication()
        : Application(800, 600, "RGLA")
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        _shader = std::make_unique<ShaderProgram>("shaders/basic.vs", "shaders/basic.fs");
        /*
        _quad = std::make_unique<Mesh>(std::vector<Vertex>({
                    {{0.5f, 0.5f, 0.0f}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}, {0.0f, 0.0f}},
                    {{0.5f, -0.5f, 0.0f}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}, {0.0f, 0.0f}},
                    {{-0.5f, -0.5f, 0.0f}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}, {0.0f, 0.0f}},
                    {{-0.5f, 0.5f, 0.0f}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}, {0.0f, 0.0f}}
            }),
            std::vector<uint>({0, 1, 3, 1, 2, 3})
        );
        */
        _texture = std::make_shared<Texture>("res/container.jpg");
        _quad = std::make_unique<TexturedQuad>(_texture, Vec2{-0.5f, -0.5f});
        _transformMatrix.Scale(Vec3(0.5f, 0.5f, 1.0f));
    }

    RGLAApplication::~RGLAApplication() {
    }

    bool RGLAApplication::ProcessFrame() {
        // float time = glfwGetTime();
        // float brightness = (sin(time) / 2.0f) + 0.5f;
        _window->ProcessInput();

        glClear(GL_COLOR_BUFFER_BIT);
        _shader->Use();
        /*
        _shader->SetFloat("brightness", brightness);
        _shader->SetInt("texture0", 0);
        _shader->SetMat4("transform", _transformMatrix);
        _texture->Use(0);
        */
        _quad->Render(*_shader);

        _window->SwapBuffers();
        return _window->ShouldBeClosed();
    }
}
