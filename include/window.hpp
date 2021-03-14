#pragma once

#include "common.hpp"
#include "math.hpp"
#include "input.hpp"

#include <GLFW/glfw3.h>

#include <memory>
#include <functional>
#include <optional>

namespace RGLA {
    class Window {
    public:
        Window(int width, int height, std::string title);
        ~Window();

        using InputCallback = std::function<void(KeyCode, InputKeyStatus)>;

        void RegisterInputCallback(InputCallback callback);
        void ClearWindow() const;
        void SwapBuffers() const;
        void SetClearColor(Vec4 color) const;
        bool ShouldBeClosed() const;

    private:
        friend void RGLAInternalInputCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

        std::optional<InputCallback> _callback;
        GLFWwindow* _window;
    };
}
