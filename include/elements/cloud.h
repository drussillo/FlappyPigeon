#ifndef CLOUD_H
#define CLOUD_H

#include "elements/element.h"
#include "engine/resource_manager.h"


class Cloud : public Element {
public:
  Cloud(ResourceManager &rm);

  void update(float dt) override;
};


#endif
