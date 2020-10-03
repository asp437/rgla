#include <iostream>
#include <rgla_config.h>
#include <application.hpp>
#include <rgla_application.hpp>
#include <vertex.hpp>

int main() {
    std::cout << "OpenGL Playground Version " << rgla_VERSION_MAJOR << "." << rgla_VERSION_MINOR << std::endl;
    std::cout << "Size of Vertex: " << sizeof(RGLA::Vertex) << std::endl;
    try {
        std::cout << "Starting..." << std::endl;
        RGLA::RGLAApplication app;
        std::cout << "Entering main loop" << std::endl;
        app.MainLoop();
        std::cout << "Exiting" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
