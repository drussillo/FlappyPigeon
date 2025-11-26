cmake_minimum_required(VERSION 4.1.2)
project(FlappyPigeon)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 23)  # use C++23

# Find packages (assuming you have GLFW and OpenGL installed)
find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

# Add source files
add_executable(FlappyPigeon 
  src/main.cpp

  src/engine/game.cpp
  src/engine/input.cpp
  src/engine/random.cpp
  src/engine/resource_manager.cpp
  src/engine/scene_manager.cpp

  src/graphics/mesh.cpp
  src/graphics/shader.cpp
  src/graphics/texture.cpp

  src/elements/element.cpp
  src/elements/pigeon.cpp
  src/elements/cloud.cpp

  src/scenes/scene.cpp
  src/scenes/mode_infinite_scene.cpp

  lib/glad/glad.c
  lib/stb/stb_image.cpp
)

# include
target_include_directories(FlappyPigeon PRIVATE include lib)

# Link libraries
target_link_libraries(FlappyPigeon PRIVATE OpenGL::GL glfw)

# Compiler options
target_compile_options(FlappyPigeon PRIVATE
  -Wall -Wextra -Wunused -Wmissing-declarations
)

