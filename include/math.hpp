#pragma once

#include "common.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace RGLA {
    typedef glm::uvec2 Vec2u;
    typedef glm::uvec3 Vec3u;
    typedef glm::uvec4 Vec4u;
    typedef glm::vec2 Vec2f;
    typedef glm::vec3 Vec3f;
    typedef glm::vec4 Vec4f;
    typedef Vec2f Vec2;
    typedef Vec3f Vec3;
    typedef Vec4f Vec4;
    typedef glm::mat2 Mat2;
    typedef glm::mat3 Mat3;

    class Mat4 : public glm::mat4 {
    public:
        using glm::mat4::mat4;

        const auto* GetValuePtr() const { return glm::value_ptr(*(static_cast<const glm::mat4*>(this))); }
    };

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
}
