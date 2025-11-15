#include "scene_manager.h"

#include <iostream>

#include "scene_names.h"
#include "resource_manager.h"

SceneManager::SceneManager(ResourceManager &rm) : rm{rm} {}

void SceneManager::changeScene(SceneNames sceneName) {
  switch(sceneName) {

    case SceneNames::NONE:
      break;

    case SceneNames::MAIN_MENU:
      // TODO: change current scene appropriately and pass rm to current scene
      break;

    // Add more scenes here

    default:
      std::cerr << "Error: attempting to switch to invalid scene '" << (int)sceneName << "'" << std::endl;
      break;
  }

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
