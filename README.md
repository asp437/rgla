# RGLA

Simple 2D graphs engine, for some of my other study projects.
It also provides some user interaction interface for mouse and keyboard.

You can use it if you want to, with respect to MIT license.

## Build

TODO: Write a build script

## Usage

## Tested OS

| OS        | Tested    | Work  | Comment   |
| --------- | --------- | ----- | --------- |
| Linux     | ✓         | -     | -         |
| Windows   | ✗         | -     | -         |
| OS X      | ✗         | -     | -         |

## Ideas of the features

There are some ideas, not a plan.

* Multiple viewpoerts/windows
* Sprites
* Tiles grid
* Sprite atlas
* Blending
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

All dependencies will be used via custom wrappers to be switched to another implementation in the future.

* OpenGL as basic graphical backend (may be switched to Vulkan)
* GLFW for cross-platform window creation and IO events
* STB for image formats decoding
