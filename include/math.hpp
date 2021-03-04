#pragma once

#include "common.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace RGLA {
    template<typename T>
    class GlmWrapper : public T {
    public:
        using T::T;

        const auto* GetValuePtr() const { return glm::value_ptr(*(static_cast<const T*>(this))); }
    };

    typedef GlmWrapper<glm::uvec2> Vec2u;
    typedef GlmWrapper<glm::uvec3> Vec3u;
    typedef GlmWrapper<glm::uvec4> Vec4u;
    typedef GlmWrapper<glm::vec2> Vec2f;
    typedef GlmWrapper<glm::vec3> Vec3f;
    typedef GlmWrapper<glm::vec4> Vec4f;
    typedef GlmWrapper<glm::bvec2> Vec2b;
    typedef GlmWrapper<glm::bvec3> Vec3b;
    typedef GlmWrapper<glm::bvec4> Vec4b;

    typedef GlmWrapper<glm::mat2> Mat2;
    typedef GlmWrapper<glm::mat3> Mat3;
    typedef GlmWrapper<glm::mat4> Mat4;

    typedef Vec2f Vec2;
    typedef Vec3f Vec3;
    typedef Vec4f Vec4;

    Mat2 IdentityMat2();
    Mat3 IdentityMat3();
    Mat4 IdentityMat4();
    Mat4 Rotate(float degree, const Vec3& axies);
    Mat4 Scale(const Vec3& slace);
    Mat4 Translate(const Vec3& translation);

    class TransformMatrix : public Mat4 {
    public:
        TransformMatrix() : Mat4(1.0f) {}
        TransformMatrix& Rotate(float degree, const Vec3& axies);
        TransformMatrix& Scale(const Vec3& scale);
        TransformMatrix& Translate(const Vec3& translation);
    };

    template<class T>
    T Clamp(T value, T low, T high) {
        if (value < low) {
            return low;
        }
        if (value > high) {
            return high;
        }
        return value;
    }
}
