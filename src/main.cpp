#include <logging.hpp>
#include <rgla_config.h>
#include <application.hpp>
#include <rgla_application.hpp>
#include <vertex.hpp>

int main() {
    RGLA::Logger::InitLogger(std::cerr, RGLA::Logger::LoggerLevel::LOG_INFO);
    RGLA::Logger::LogDebug() << "OpenGL Playground Version " << rgla_VERSION_MAJOR << "." << rgla_VERSION_MINOR << std::endl;
    RGLA::Logger::LogDebug() << "Size of Vertex: " << sizeof(RGLA::Vertex) << std::endl;
    try {
        RGLA::Logger::LogInfo() << "Starting..." << std::endl;
        RGLA::RGLAApplication app;
        RGLA::Logger::LogInfo() << "Entering main loop" << std::endl;
        app.MainLoop();
        RGLA::Logger::LogInfo() << "Exiting" << std::endl;
    } catch (const std::exception& e) {
        RGLA::Logger::LogError() << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
