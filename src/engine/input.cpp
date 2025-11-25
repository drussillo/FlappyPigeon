#include "engine/input.h"

#include <GLFW/glfw3.h>

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  if(scancode == mods) {;}  // getting rid of the annoying warning
  
  if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, 1);
}

void initInput() {
  glfwSetKeyCallback(glfwGetCurrentContext(), key_callback);
}

