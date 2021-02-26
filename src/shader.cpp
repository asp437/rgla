#include <shader.hpp>

#include <glad/glad.h>

#include <fstream>
#include <sstream>

namespace RGLA {
    ShaderProgram::ShaderProgram(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) {
        std::ifstream vertexShaderFile(vertexShaderPath);
        std::ifstream fragmentShaderFile(fragmentShaderPath);
        std::stringstream vertexShader;
        std::stringstream fragmentShader;
        vertexShader << vertexShaderFile.rdbuf();
        fragmentShader << fragmentShaderFile.rdbuf();
        Load(vertexShader.str(), fragmentShader.str());
    }

    ShaderProgram::~ShaderProgram() {
        if (_id) {
            glDeleteProgram(_id);
        }
    }

    void ShaderProgram::Load(const std::string& vertexShader, const std::string& fragmentShader) {
        Shader vertex = Shader(vertexShader, GL_VERTEX_SHADER);
        Shader fragment = Shader(fragmentShader, GL_FRAGMENT_SHADER);
        _id = Link(vertex, fragment);
    }

    uint ShaderProgram::Link(const Shader& vertex, const Shader& fragment) const {
        uint id = glCreateProgram();
        int success;
        char errorInfo[512];
        glAttachShader(id, vertex.GetId());
        glAttachShader(id, fragment.GetId());
        glLinkProgram(id);

        glGetProgramiv(id, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(id, sizeof(errorInfo), nullptr, errorInfo);
            std::stringstream errorMsg;
            errorMsg << "Program link error: " << errorInfo;
            throw std::runtime_error(errorMsg.str());
        }

        return id;
    }

    void ShaderProgram::Use() const {
        glUseProgram(_id);
    }

    void ShaderProgram::SetFloat(const std::string& name, float value) const {
        glUniform1f(glGetUniformLocation(_id, name.c_str()), value);
    }

    void ShaderProgram::SetInt(const std::string& name, int value) const {
        glUniform1i(glGetUniformLocation(_id, name.c_str()), value);
    }

    void ShaderProgram::SetVec2(const std::string& name, Vec2 value) const {
        glUniform2fv(glGetUniformLocation(_id, name.c_str()), 1, value.GetValuePtr());
    }

    void ShaderProgram::SetVec3(const std::string& name, Vec3 value) const {
        glUniform3fv(glGetUniformLocation(_id, name.c_str()), 1, value.GetValuePtr());
    }

    void ShaderProgram::SetVec4(const std::string& name, Vec4 value) const {
        glUniform4fv(glGetUniformLocation(_id, name.c_str()), 1, value.GetValuePtr());
    }

    void ShaderProgram::SetMat2(const std::string& name, Mat2 value) const {
        glUniformMatrix2fv(glGetUniformLocation(_id, name.c_str()), 1, GL_FALSE, value.GetValuePtr());
    }

    void ShaderProgram::SetMat3(const std::string& name, Mat3 value) const {
        glUniformMatrix3fv(glGetUniformLocation(_id, name.c_str()), 1, GL_FALSE, value.GetValuePtr());
    }

    void ShaderProgram::SetMat4(const std::string& name, Mat4 value) const {
        glUniformMatrix4fv(glGetUniformLocation(_id, name.c_str()), 1, GL_FALSE, value.GetValuePtr());
    }

    Shader::Shader(const std::string& code, uint type)
        : _type(type)
    {
        RGLA_UNUSED(_type);
        int success;
        char errorInfo[512];
        const char *codePtr = code.c_str();
        _id = glCreateShader(type);
        glShaderSource(_id, 1, &codePtr, nullptr);
        glCompileShader(_id);
        glGetShaderiv(_id, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(_id, sizeof(errorInfo), nullptr, errorInfo);
            std::stringstream errorMsg;
            errorMsg << "Shader compile error: " << errorInfo;
            throw std::runtime_error(errorMsg.str());
        }
    }

    Shader::~Shader() {
        if (_id) {
            glDeleteShader(_id);
        }
    }
}
