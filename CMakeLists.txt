cmake_minimum_required(VERSION 4.1.2)
project(FlappyPigeon)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 23)  # use C++23

# Find packages (assuming you have GLFW and OpenGL installed)
find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

# Add source files
add_executable(FlappyPigeon 
  src/glad.c
  src/main.cpp
  src/scene.cpp
  src/element.cpp
  src/mesh.cpp
  src/shader.cpp
  src/input.cpp
)

# include
target_include_directories(FlappyPigeon PRIVATE include)

# Link libraries
target_link_libraries(FlappyPigeon PRIVATE OpenGL::GL glfw)

# Compiler options
target_compile_options(FlappyPigeon PRIVATE
  -Wall -Wextra -Wunused -Wmissing-declarations
)

