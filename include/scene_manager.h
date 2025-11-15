#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H


#include <string>
#include <memory>

#include "scene.h"
#include "resource_manager.h"


class SceneManager {
public:
  SceneManager(ResourceManager &rm);
  
  void changeScene(const std::string &sceneName);
  void changeSceneToNext();  // uses currentScene->nextScene
  void updateCurrent(double dt);
  void renderCurrent() const;

private:
  std::unique_ptr<Scene> currentScene;
  ResourceManager &rm;
};

#endif
