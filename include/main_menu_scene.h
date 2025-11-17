#ifndef MAIN_MENU_SCENE_H
#define MAIN_MENU_SCENE_H

#include "scene.h"

#include "resource_manager.h"


class MainMenuScene : public Scene {
public:
  MainMenuScene(ResourceManager &rm);

  void init() override;
};


#endif
