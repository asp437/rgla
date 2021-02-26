#pragma once

#include "common.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <memory>

#include "window.hpp"

namespace RGLA {
    class Application {
    public:
        Application(uint width, uint height, std::string name) {
            glfwInit();
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            _window = std::make_unique<Window>(width, height, name);
            LoadOpenGLFunctions(); // Should be called after window creation (context binding)
        }

        virtual ~Application() {
            glfwTerminate();
        }

        void MainLoop() {
            while (true) {
                if (ProcessFrame()) {
                    break;
                }
                glfwPollEvents();
            }
        }

        void SwitchBlending(bool on) {
            if (on) {
                glEnable(GL_BLEND);
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            } else {
                glDisable(GL_BLEND);
            }
        }

        // Called each frame. If ProcessFrame returned true, the application will be stopped
        virtual bool ProcessFrame() = 0;

    private:
        void LoadOpenGLFunctions() const {
            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
                throw std::runtime_error("Can't load OpenGL functions");
            }
        }

    protected:
        std::unique_ptr<Window> _window;
    };
}
