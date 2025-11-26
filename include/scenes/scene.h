#ifndef SCENE_H
#define SCENE_H

#include <glm/glm.hpp>
#include <vector>
#include <memory>

#include "engine/resource_manager.h"
#include "elements/element.h"
#include "scenes/scene_names.h"

class Scene {
public:
  Scene(ResourceManager &rm);
  virtual ~Scene() = default;

  // loads resources, generates elements, and adds elements to scene
  virtual void init() = 0;
  virtual void exit() = 0;

  SceneNames getNextScene() const;
  
  void setBackgroundColor(const glm::vec4 &newBackgroundColor);
  void addElement(std::shared_ptr<Element> newElement);

  virtual void update(float dt);
  void render() const;

protected:
  ResourceManager &rm;
  std::vector<std::shared_ptr<Element>> elements = {};
  glm::vec4 backgroundColor = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);
  bool finished = false;
  SceneNames nextScene = SceneNames::NONE;  // modify internally later (idk how i have no idea)
};


#endif
