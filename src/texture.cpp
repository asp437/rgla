#include <texture.hpp>

#include <glad/glad.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace RGLA {
    Texture::~Texture() {
        if (_id) {
            glDeleteTextures(1, &_id);
        }
    }

    void Texture::BindData() {
        RGLA_ENSURE(_data, "Texture data is null");
        glGenTextures(1, &_id);
        UpdateData();
    }

    void Texture::UpdateData() {
        // TODO: Dynamic source image format detection
        glBindTexture(GL_TEXTURE_2D, _id);
        if (_channels == 4) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _data);
        } else {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, _data);
        }
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    void Texture::Use(uint textureUnit) const {
        glActiveTexture(GL_TEXTURE0 + textureUnit);
        glBindTexture(GL_TEXTURE_2D, _id);
    }

    void Texture::SetFilteringMode(TextureFilter filter) {
        glBindTexture(GL_TEXTURE_2D, _id);
        switch (filter) {
            case TextureFilter::TF_NEAREST:
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                break;
            case TextureFilter::TF_LINEAR:
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                break;
        }
    }

    TextureFilter Texture::GetFilteringMode() const {
        return TextureFilter::TF_LINEAR; // TODO:
    }

    FileTexture::FileTexture(const std::string& fileName, bool flipVertical) {
        stbi_set_flip_vertically_on_load(flipVertical);
        _data = stbi_load(fileName.c_str(), &_width, &_height, &_channels, 0);
        if (!_data) {
            throw std::runtime_error("Can't load image " + fileName);
        }
        BindData();
    }

    FileTexture::~FileTexture() {
        if (_data) {
            stbi_image_free(_data);
            _data = nullptr;
        }
    }

    InMemoryTexture::InMemoryTexture(const int width, const int height, const int channels) {
        RGLA_ENSURE(channels == 4, "InMemoryTexture can be only with 4 channels");
        _width = width;
        _height = height;
        _channels = channels;
        _data = (unsigned char*) malloc(_width * _height * _channels);
        memset(_data, 0x00, _width * _height * _channels);
        BindData();
    }

    InMemoryTexture::~InMemoryTexture() {
        free(_data);
    }

    Pixel InMemoryTexture::GetPixel(int x, int y) const {
        if (x < 0 || x >= _width || y < 0 || y >= _height) {
            throw std::runtime_error("Try to get pixel out of bounds of the texture");
        }
        uint32* addr = (uint32*)(_data + (x + y * _width) * _channels);
        return Pixel(*addr);
    }

    void InMemoryTexture::SetPixel(int x, int y, Pixel color) {
        if (x < 0 || x >= _width || y < 0 || y >= _height) {
            throw std::runtime_error("Try to set pixel out of bounds of the texture");
        }
        uint32* addr = (uint32*)(_data + (x + y * _width) * _channels);
        (*addr) = color.data;
    }
}
