#include "math.hpp"

namespace RGLA {
    Mat2 IdentityMat2() { return Mat2(1.0f); }
    Mat3 IdentityMat3() { return Mat3(1.0f); }
    Mat4 IdentityMat4() { return Mat4(1.0f); }

    TransformMatrix& TransformMatrix::Rotate(float degree, const Vec3& axies) {
        *(static_cast<glm::mat4*>(this)) = glm::rotate(*this, glm::radians(degree), axies);
        return *this;
    }

    TransformMatrix& TransformMatrix::Scale(const Vec3& scale) {
        *(static_cast<glm::mat4*>(this)) = glm::scale(*this, scale);
        return *this;
    }

    TransformMatrix& TransformMatrix::Translate(const Vec3& translation) {
        *(static_cast<glm::mat4*>(this)) = glm::translate(*this, translation);
        return *this;
    }

    Mat4 Rotate(float degree, const Vec3& axies) {
        TransformMatrix result;
        return result.Rotate(degree, axies);
    }

    Mat4 Scale(const Vec3& slace) {
        TransformMatrix result;
        return result.Scale(slace);
    }

    Mat4 Translate(const Vec3& translation) {
        TransformMatrix result;
        return result.Translate(translation);
    }
}
