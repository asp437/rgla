#pragma once

#include "application.hpp"
#include "math.hpp"
#include "window.hpp"
#include "mesh.hpp"
#include "shader.hpp"
#include "texture.hpp"

#include <vector>
#include <memory>

namespace RGLA {
    class RGLAApplication : public Application {
    public:
        RGLAApplication();
        ~RGLAApplication();

        bool ProcessFrame() override;
    private:
        std::unique_ptr<Mesh> _quad;
        std::unique_ptr<ShaderProgram> _shader;
        std::unique_ptr<Texture> _texture;
        std::unique_ptr<Texture> _faceTexture;
        TransformMatrix _transformMatrix;
    };
}
