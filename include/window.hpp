#pragma once

#include "common.hpp"
#include "math.hpp"

#include <GLFW/glfw3.h>

namespace RGLA {
    class Window {
    public:
        Window(int width, int height, std::string title);
        ~Window();

        void ProcessInput() const;
        void ClearWindow() const;
        void SwapBuffers() const;
        void SetClearColor(Vec4 color) const;
        bool ShouldBeClosed() const;
    private:
        GLFWwindow* _window;
    };
}
