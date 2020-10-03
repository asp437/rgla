# RGLA

Simple 2D graphs engine, for some of my other study projects.
It also provides some user interaction interface for mouse and keyboard.

You can use it if you want to, with respect to MIT license.

## Build

Currently just basic cmake steps. Generate configuration for preffered build system and build it.

## Usage

Basic example can be found in `rgla_application.{cpp,hpp}`.
It also use some of the image resources which can be found at learnopengl.com

## Dependencies

All dependencies (except OpenGL) will be used via custom wrappers to be switched to another implementation in the future.

* OpenGL as basic graphical backend (may be switched to Vulkan)
* GLM as base for math classes to use with OpenGL
* GLFW for cross-platform window creation and IO events
* GLAD for loading OpenGL functions (source code generated at https://glad.dav1d.de/ and placed in this repo)
* STB for image formats decoding (source code included in this repo)
