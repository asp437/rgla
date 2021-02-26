#pragma once

#include "common.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <memory>
#include <chrono>

#include "window.hpp"
#include "logging.hpp"

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
                _framesSinceLastDebugPrint++;
                glfwPollEvents();
                PrintDebugInfo();
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

        virtual void PrintDebugInfo() const {
            auto now = std::chrono::steady_clock::now();
            auto dur = now - _lastDebugPrint;
            if (dur >= std::chrono::seconds(1)) {
                Logger::LogInfo() << "FPS: " << _framesSinceLastDebugPrint << std::endl;
                _lastDebugPrint = now;
                _framesSinceLastDebugPrint = 0;
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

        mutable std::chrono::time_point<std::chrono::steady_clock> _lastDebugPrint = std::chrono::steady_clock::now();
        mutable uint32 _framesSinceLastDebugPrint = 0;
    };
}
