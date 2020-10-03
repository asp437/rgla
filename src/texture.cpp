#include <texture.hpp>

#include <glad/glad.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace RGLA {
    Texture::Texture(const std::string& fileName, bool flipVertical) {
        stbi_set_flip_vertically_on_load(flipVertical);
        _stbData = stbi_load(fileName.c_str(), &_width, &_height, &_channels, 0);
        if (!_stbData) {
            throw std::runtime_error("Can't load image " + fileName);
        }
        glGenTextures(1, &_id);
        glBindTexture(GL_TEXTURE_2D, _id);
        // TODO: Dynamic source image format detection
        if (_channels == 4) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _stbData);
        } else {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, _stbData);
        }
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    Texture::~Texture() {
        if (_stbData) {
            stbi_image_free(_stbData);
            _stbData = nullptr;
        }
        if (_id) {
            glDeleteTextures(1, &_id);
        }
    }

    void Texture::Use(uint textureUnit) const {
        glActiveTexture(GL_TEXTURE0 + textureUnit);
        glBindTexture(GL_TEXTURE_2D, _id);
    }
}
