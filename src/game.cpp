#include "game.h"

#include "scene_manager.h"
#include "resource_manager.h"


Game::Game() : rm(), sm(rm) {}


void Game::init() {
  sm.changeScene("MainMenu");
}

void Game::mainLoop() {
  double dt = 0.0;
  // TODO: add deltatime calculation logic

  while(true) {
    sm.updateCurrent(dt);
    sm.renderCurrent();
    sm.changeSceneToNext();
  }
}

