#ifndef GAME_H
#define GAME_H


#include "resource_manager.h"
#include "scene_manager.h"

class Game {
public:
  Game();
  
  void init();  // load initial scene
  void mainLoop();  // pass resources to scenes (will use for current scene)

private:
  ResourceManager rm;
  SceneManager sm;
};


#endif
