#ifndef MAIN_MENU_SCENE_H
#define MAIN_MENU_SCENE_H

#include "scenes/scene.h"
#include "engine/resource_manager.h"


class MainMenuScene : public Scene {
public:
  MainMenuScene(ResourceManager &rm);

  void init() override;
  void exit() override;

  void update(float dt) override;
};


#endif
