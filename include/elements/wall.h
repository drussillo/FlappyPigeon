#ifndef WALL_H
#define WALL_H

#include <vector>
#include <memory>

#include "elements/element.h"
#include "engine/resource_manager.h"


class Wall : public Element {
public:
  Wall(ResourceManager &rm, int wallNumber);

  void setPassed(bool value) override;
  bool getPassed() const override;

  void draw() override;
  void update(float dt) override;
  bool collidesWith(std::shared_ptr<Element> element) override;

private:
  float gapY;
  float gapSize;
  bool passed = false;

  void randomize();
};


#endif
