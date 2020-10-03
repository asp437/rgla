#pragma once

#include "common.hpp"

namespace RGLA {
    // TODO: Split OpenGL image and decoded raw image
    // Also support creation of image without file
    class Texture {
    public:
        Texture(const std::string& fileName, bool flipVertical = false);
        virtual ~Texture();

        void Use(uint textureUnit) const;

    private:
        uint _id = 0;
        int _width;
        int _height;
        int _channels;
        unsigned char* _stbData = nullptr;
    };
}
