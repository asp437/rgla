#pragma once

#include "common.hpp"

namespace RGLA {
    // TODO: Split OpenGL image and decoded raw image
    // Also support creation of image without file
    class Texture {
    public:
        virtual ~Texture();

        void Use(uint textureUnit) const;
    protected:
        Texture() = default;
        void BindData();
        void UpdateData();

        uint _id = 0;
        int _width;
        int _height;
        int _channels;
        unsigned char* _data = nullptr;
    };

    class FileTexture : public Texture {
    public:
        FileTexture(const std::string& fileName, bool flipVertical = false);
        ~FileTexture();
    private:
    };

    class InMemoryTexture : public Texture {
    public:
        using Pixel = uint32;

        InMemoryTexture(const int width, const int height, const int channels);
        ~InMemoryTexture();

        Pixel GetPixel(int x, int y) const;
        void SetPixel(int x, int y, Pixel color);
    private:
    };
}
