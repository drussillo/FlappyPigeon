#include "game.h"

#include "scene_manager.h"
#include "resource_manager.h"
#include "scene_names.h"


Game::Game() : rm(), sm(rm) {}


void Game::init() {
  sm.changeScene(SceneNames::MAIN_MENU);
}

void Game::mainLoop() {
  float dt = 0.0;
  // TODO: add deltatime calculation logic

  while(true) {
    sm.updateCurrent(dt);
    sm.renderCurrent();
    sm.changeSceneToNext();
  }
}

