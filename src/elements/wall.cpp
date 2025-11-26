#include "elements/wall.h"

#include <memory>

#include "engine/random.h"


Wall::Wall(ResourceManager &rm, int wallNumber)
           : Element(rm.getMesh("quad"), rm.getShader("defaultShader"), rm.getTexture("brick_wall")) {


  randomize();
  setScale(glm::vec2(14.0f, 90.0f));

  position.x = wallNumber * 52 + 80;

  velocity.x = -0.2;
}


void Wall::draw() {
  setRotation(0.0f);
  position.x -= 14.0f;
  position.y = gapY - 90.0f - gapSize / 2;
  Element::applyModel();
  Element::draw();
  setRotation(180.0f);
  position.x += 14.0f;
  position.y = gapY + 90.0f + gapSize / 2;
  Element::applyModel();
  Element::draw();
}

void Wall::update(float dt) {
  if(position.x < -14.0f) {
    position.x = 175.0f;
    randomize();
  }

  position += velocity * dt;
}

bool Wall::collidesWith(std::shared_ptr<Element> element) {
  position.x -= 14;
  position.y = gapY - 90.0f - gapSize / 2 - 5;
  bool bottom = Element::collidesWith(element);
  position.y = gapY + gapSize / 2 + 5;
  bool top = Element::collidesWith(element);
  position.x += 14;
  return bottom || top;
}


void Wall::randomize() {
  gapY = static_cast<float>(Random::range(25, 65));  // 25 - 65
  gapSize = static_cast<float>(Random::range(30, 45));  // 30 - 45
}


