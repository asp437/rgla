# Garmez
Simple 2D graphs engine, for some of my other study projects.

You can use it if you want to, with respect to MIT license.

## Things to implement

There are some ideas, not a plan.

* Multiple viewpoerts/windows
* Sprites
* Tiles grid
* Sprite atlas
* Custom shaders
* Per pixel collision
* BBox collision
* Mouse events (clicks and other stuff)
* Lightning?
* Z-ordering
* Sprite as grid of pixels (or even screen as 2D grid of pixels)
* Font rendering (raster)
* Font rendering (vector) (use STB for it?)

## Dependencies

All dependencies are used via custom wrappers to be switched to another implementation in the future.

* OpenGL as basic graphical backend (may be switched to Vulkan)
* GLFW for cross-platform window creation and IO events
* STB for image formats decoding
