#include "elements/cloud.h"

#include <glm/glm.hpp>

#include "engine/resource_manager.h"
#include "engine/random.h"


Cloud::Cloud(ResourceManager &rm) 
             : Element(rm.getMesh("quad"), rm.getShader("defaultShader"), rm.getTexture("cloud_1")) {
  setPosition(glm::vec2(static_cast<float>(Random::range(0, 250)), static_cast<float>(Random::range(10, 75))));
  velocity.x = static_cast<float>(Random::range(3, 15)) / -100;  // 0.02 - 0.15
  setScale(glm::vec2(23.0f * -velocity.x * 10, 6.0f * -velocity.x * 10));
}

void Cloud::update(float dt) {
  if(position.x < -scale.x) {
    position = glm::vec2(static_cast<float>(Random::range(160, 200)), static_cast<float>(Random::range(10, 75)));
    velocity.x = static_cast<float>(Random::range(3, 15)) / -100;  // 0.02 - 0.15
    setScale(glm::vec2(23.0f * -velocity.x * 10, 6.0f * -velocity.x * 10));
  }


  position += velocity; // * deltaTime
}
