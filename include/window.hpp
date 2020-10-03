#pragma once

#include "common.hpp"

#include <GLFW/glfw3.h>

namespace RGLA {
    class Window {
    public:
        Window(int width, int height, std::string title);
        ~Window();

        void ProcessInput() const;
        void SwapBuffers() const;
        bool ShouldBeClosed() const;
    private:
        GLFWwindow* _window;
    };
}
