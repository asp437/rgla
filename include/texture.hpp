#pragma once

#include "common.hpp"
#include "math.hpp"

namespace RGLA {
    enum class TextureFilter {
        TF_NEAREST,
        TF_LINEAR,
    };

    union Pixel {
        struct {
            uint8 r;
            uint8 g;
            uint8 b;
            uint8 a;
        } components;
        uint32 data;

        Pixel() : Pixel(0x000000FF) {}
        Pixel(uint32 color) : data(color) {}
        Pixel(uint8 r, uint8 g, uint8 b, uint8 a = 0xFF) : components({r, g, b, a}) {}
        Pixel(float r, float g, float b, float a = 1.0f) {
            components.r = int(r * 255.0f);
            components.g = int(g * 255.0f);
            components.b = int(b * 255.0f);
            components.a = int(a * 255.0f);
        }
    };

    class Texture {
    public:
        virtual ~Texture();

        void Use(uint textureUnit) const;
        void UpdateData();
        void SetFilteringMode(TextureFilter filter);
        TextureFilter GetFilteringMode() const;

    protected:
        Texture() = default;
        void BindData();

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
        InMemoryTexture(const int width, const int height, const int channels);
        ~InMemoryTexture();

        Pixel GetPixel(int x, int y) const;
        void SetPixel(int x, int y, Pixel color);
    private:
    };
}
