#include "pigeon.h"

#include <GLFW/glfw3.h>
#include <memory>


Pigeon::Pigeon(std::shared_ptr<Mesh> mesh,
               std::shared_ptr<Shader> shader) 
               : Element(mesh, shader) {}


void Pigeon::update() {
  velocity.y -= 0.000981f;
  if(glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_SPACE) == GLFW_PRESS) {
    velocity.y = 0.04f;
  }

  // if(position.y < -0.5f) velocity.y = 0.04;
  // if(velocity.y > 0) rotation += 1.0f;
  // else rotation -= 1.0f;
  // scale.x += velocity.y;
  // scale.y += velocity.y;
}
