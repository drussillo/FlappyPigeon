#include "input.h"

#include <GLFW/glfw3.h>
#include <iostream>

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
    std::cout << "Jump! ";
  if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, 1);
}

void initInput() {
  glfwSetKeyCallback(glfwGetCurrentContext(), key_callback);
}

