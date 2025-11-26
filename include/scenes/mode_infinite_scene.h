#ifndef MAIN_MENU_SCENE_H
#define MAIN_MENU_SCENE_H

#include "scenes/scene.h"

#include "engine/resource_manager.h"


class ModeInfiniteScene : public Scene {
public:
  ModeInfiniteScene(ResourceManager &rm);

  void init() override;
  void update(float dt) override;
  void exit() override;
};


#endif
