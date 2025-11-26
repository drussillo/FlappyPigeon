#include "elements/cloud.h"

#include <glm/glm.hpp>

#include "engine/resource_manager.h"


Cloud::Cloud(ResourceManager &rm) 
             : Element(rm.getMesh("quad"), rm.getShader("defaultShader"), rm.getTexture("cloud_1")) {
  setPosition(glm::vec2(160.0f, 0.0f));
  // TODO random y coord
  setScale(glm::vec2(35.0f, 14.0f));
}

void Cloud::update(float dt) {
  velocity.x = -0.1f;
  if(position.x < -scale.x) {
    position.x = 160.0f;
  }


  position += velocity; // * deltaTime
}
