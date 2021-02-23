#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <window.hpp>

#include <stdexcept>
#include <iostream>

namespace RGLA {
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
        glfwMakeContextCurrent(_window);
        glfwSetFramebufferSizeCallback(_window, ResizeCallback);
    }

    Window::~Window() {
        glfwDestroyWindow(_window);
        _window = nullptr;
    }

    void Window::ProcessInput() const {
        if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(_window, true);
        }
    }

    void Window::SwapBuffers() const {
        glfwSwapBuffers(_window);
    }

    bool Window::ShouldBeClosed() const {
        return glfwWindowShouldClose(_window);
    }
}
