#pragma once

#include "common.hpp"
#include "math.hpp"

namespace RGLA {
    class Shader {
    public:
        Shader(const std::string& code, uint type);
        virtual ~Shader();

        uint GetId() const { return _id; }
    private:
        uint _type;
        uint _id = 0;
    };

    class ShaderProgram {
    public:
        ShaderProgram(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
        ShaderProgram(std::istream& vertexShader, std::istream& fragmentShader);
        virtual ~ShaderProgram();

        void Use() const;

        void SetFloat(const std::string& name, float value) const;
        void SetInt(const std::string& name, int value) const;

        void SetVec2(const std::string& name, Vec2 value) const;
        void SetVec3(const std::string& name, Vec3 value) const;
        void SetVec4(const std::string& name, Vec4 value) const;
        void SetMat2(const std::string& name, Mat2 value) const;
        void SetMat3(const std::string& name, Mat3 value) const;
        void SetMat4(const std::string& name, Mat4 value) const;
    private:
        void Load(const std::string& vertexShader, const std::string& fragmentShader);
        uint Link(const Shader& vertex, const Shader& fragment) const;

        uint _id = 0;
    };
}
