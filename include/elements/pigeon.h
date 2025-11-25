#ifndef PIGEON_H
#define PIGEON_H


#include "elements/element.h"
#include "engine/resource_manager.h"

class Pigeon : public Element {
public:
  Pigeon(ResourceManager &rm);

  void update(float dt) override;

private:
  bool isJumping = false;
};


#endif
