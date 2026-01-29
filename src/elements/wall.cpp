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


void Wall::setPassed(bool value) {
  passed = value;
}

bool Wall::getPassed() const {
  return passed;
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
    setPassed(false);
    position.x = 188.0f;
    randomize();
  }

  position += velocity * dt;
}

bool Wall::collidesWith(std::shared_ptr<Element> element) {
  const float vertTolerance = 2;
  const float horTolerance = 2;
  scale.x -= horTolerance * 2;
  position.x -= 14 - horTolerance;
  position.y = gapY - 90.0f - gapSize / 2 - vertTolerance;
  bool bottom = Element::collidesWith(element);
  position.y = gapY + gapSize / 2 + vertTolerance;
  bool top = Element::collidesWith(element);
  position.x += 14 - horTolerance;
  scale.x += horTolerance * 2;
  return bottom || top;
}


void Wall::randomize() {
  gapY = static_cast<float>(Random::range(25, 65));  // 25 - 65
  gapSize = static_cast<float>(Random::range(30, 45));  // 30 - 45
}


