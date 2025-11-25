#include "engine/scene_manager.h"

#include <iostream>

#include "scenes/scene_names.h"
#include "engine/resource_manager.h"

#include "scenes/scene.h"
#include "scenes/main_menu_scene.h"
// Add new scenes here

SceneManager::SceneManager(ResourceManager &rm) : rm{rm} {}

void SceneManager::changeScene(SceneNames sceneName) {
  if(currentScene != nullptr) {
    currentScene->exit();
  }

  switch(sceneName) {
    case SceneNames::NONE:
      break;
    case SceneNames::MAIN_MENU:
      currentScene = std::make_unique<MainMenuScene>(rm);
      break;

    // Add more scenes here

    default:
      std::cerr << "Error: attempting to switch to invalid scene '" << (int)sceneName << "'" << std::endl;
      return;
  }

  currentScene->init();
}

void SceneManager::changeSceneToNext() {
  if(currentScene->getNextScene() != SceneNames::NONE) {
    changeScene(currentScene->getNextScene());
  }
}

void SceneManager::updateCurrent(float dt) {
  currentScene->update(dt);
}

void SceneManager::renderCurrent() const {
  currentScene->render();
}
