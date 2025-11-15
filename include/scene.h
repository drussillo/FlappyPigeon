#ifndef SCENE_H
#define SCENE_H

#include <glm/glm.hpp>
#include <vector>
#include <memory>

#include "element.h"
#include "scene_names.h"

class Scene {
public:
  Scene() = default;
  Scene(const std::vector<std::shared_ptr<Element>> &elements,
        const glm::vec4 &backgroundColor=glm::vec4(0.2, 0.2, 0.2, 1.0));

  SceneNames getNextScene() const;
  
  void setBackgroundColor(const glm::vec4 &newBackgroundColor);
  void addElement(std::shared_ptr<Element> newElement);

  void update(float dt);
  void render() const;

private:
  std::vector<std::shared_ptr<Element>> elements;
  glm::vec4 backgroundColor;
  bool finished;
  SceneNames nextScene;  // modify internally
};


#endif
