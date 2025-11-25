#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H


#include <memory>

#include "scenes/scene.h"
#include "scenes/scene_names.h"
#include "engine/resource_manager.h"


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
