#pragma once

#include "math.hpp"

namespace RGLA {
    struct Vertex {
        Vec3f pos;
        float padding0;

        Vec4f color;

        Vec2f texCoord;
        float padding1[2];
    };

    static_assert(sizeof(Vertex) == 48, "Vertex size should be 48 bytes");
    static_assert(offsetof(Vertex, pos) == 0, "Vertex offset of pos should be 0");
    static_assert(offsetof(Vertex, color) == 16, "Vertex offset of color should be 16");
    static_assert(offsetof(Vertex, texCoord) == 32, "Vertex offset of texCoord should be 32");
}
