#include "scene_manager.h"

#include "resource_manager.h"

SceneManager::SceneManager(ResourceManager &rm) : rm{rm} {}

void SceneManager::changeScene(const std::string &sceneName) {
  if(!sceneName.empty()) {
    // TODO: make enum instead of string for different scenetypes?
    // TODO: change current scene appropriately and pass to current scene
  }
}

void SceneManager::changeSceneToNext() {
  if(!currentScene->nextScene.empty()) {
    changeScene(currentScene->nextScene);
  }
}

void SceneManager::updateCurrent(double dt) {
  currentScene->update(dt);
}

void SceneManager::renderCurrent() const {
  currentScene->render();
}
