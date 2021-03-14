#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "window.hpp"

#include <unordered_map>
#include <stdexcept>
#include <iostream>

namespace {
    static std::unordered_map<void*, RGLA::Window*> _CreatedWindows;
}

namespace RGLA {
    void RGLAInternalInputCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        RGLA_UNUSED(window);
        RGLA_UNUSED(key);
        RGLA_UNUSED(scancode);
        RGLA_UNUSED(action);
        RGLA_UNUSED(mods);
        if (_CreatedWindows.count(window) == 0) {
            return;
        }
        auto* rglaWindow = _CreatedWindows.at(window);
        if (rglaWindow->_callback) {
            (*rglaWindow->_callback)(static_cast<KeyCode>(key), static_cast<InputKeyStatus>(action));
        }
    }

    void ResizeCallback(GLFWwindow* window, int width, int height) {
        RGLA_UNUSED(window);
        if (glViewport) {
            glViewport(0, 0, width, height);
        }
    }

    Window::Window(int width, int height, std::string title) {
        _window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (_window == nullptr) {
            throw std::runtime_error("Can't create window");
        }
        _CreatedWindows.insert_or_assign(_window, this);
        glfwMakeContextCurrent(_window);
        glfwSetFramebufferSizeCallback(_window, ResizeCallback);
        glfwSetKeyCallback(_window, RGLAInternalInputCallback);
    }

    Window::~Window() {
        glfwDestroyWindow(_window);
        _window = nullptr;
    }

    void Window::SetClearColor(Vec4 color) const {
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void Window::RegisterInputCallback(InputCallback callback) {
        _callback = callback;
    }

    void Window::ClearWindow() const {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Window::SwapBuffers() const {
        glfwSwapBuffers(_window);
    }

    bool Window::ShouldBeClosed() const {
        return glfwWindowShouldClose(_window);
    }
}
