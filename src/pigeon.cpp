#include "pigeon.h"

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <memory>

#include "element.h"
#include "mesh.h"
#include "shader.h"

Pigeon::Pigeon(const std::shared_ptr<Mesh> mesh,
               const std::shared_ptr<Shader> shader) 
               : Element(mesh, shader) {
  setPosition(glm::vec2(-0.5f, 0.5f));
  setScale(glm::vec2(0.2, 0.2f));
}


void Pigeon::update() {
  velocity.y -= 0.000981f;
  int spaceKey = glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_SPACE);
  if(spaceKey == GLFW_PRESS && !isJumping) {
    isJumping = true;
    velocity.y = 0.03f;
  }
  if(spaceKey == GLFW_RELEASE) {
    isJumping = false;
  }
  // if(position.y < -0.5f) velocity.y = 0.04;
  // if(velocity.y > 0) rotation += 1.0f;
  // else rotation -= 1.0f;
  // scale.x += velocity.y;
  // scale.y += velocity.y;

  position += velocity; // * deltaTime
}
