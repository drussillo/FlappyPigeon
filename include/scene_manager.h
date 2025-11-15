#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H


#include <memory>

#include "scene.h"
#include "scene_names.h"
#include "resource_manager.h"


class SceneManager {
public:
  SceneManager(ResourceManager &rm);
  
  void changeScene(SceneNames sceneName);
  void changeSceneToNext();  // uses currentScene->nextScene
  void updateCurrent(float dt);
  void renderCurrent() const;

private:
  std::unique_ptr<Scene> currentScene;
  ResourceManager &rm;
};

#endif
