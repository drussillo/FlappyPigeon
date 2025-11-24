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
  setPosition(glm::vec2(40.0f, 40.0f));
  setScale(glm::vec2(12.0f, 9.0f));
}


void Pigeon::update(float dt) {
  velocity.y -= 0.03f;
  int spaceKey = glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_SPACE);
  if(spaceKey == GLFW_PRESS && !isJumping) {
    isJumping = true;
    velocity.y = 1.05f;
  }
  if(spaceKey == GLFW_RELEASE) {
    isJumping = false;
  }
  
  setRotation(velocity.y * 10);

  // if(position.y <= 0) {
  //   if(velocity.y > -10.0f) velocity.y = 10.0f;
  //   else { position.y = 1.0f; velocity.y = -(velocity.y) * 3/4; }
  // }

  // if(velocity.y > 0) rotation += 1.0f;
  // else rotation -= 1.0f;
  // scale.x += velocity.y;
  // scale.y += velocity.y;

  position += velocity; // * deltaTime
}
