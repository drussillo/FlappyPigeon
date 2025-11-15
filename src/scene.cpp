#include "scene.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector>
#include <memory>

#include "element.h"


Scene::Scene(const std::vector<std::shared_ptr<Element>> &elements,
             const glm::vec4 &backgroundColor)
             : elements{elements},
               backgroundColor{backgroundColor} {}


SceneNames Scene::getNextScene() const {
  return nextScene;
}


void Scene::setBackgroundColor(const glm::vec4 &newBackgroundColor) {
  backgroundColor = newBackgroundColor;
}

void Scene::addElement(std::shared_ptr<Element> newElement) {
  elements.push_back(newElement);
}


void Scene::update(float dt) {
  for(std::shared_ptr<Element> &element: elements) {
    element->update(dt);
    element->applyModel();
  }
}

void Scene::render() const {
  glClearColor(backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
  glClear(GL_COLOR_BUFFER_BIT);
  for(const std::shared_ptr<Element> &element : elements) {
    element->draw();
  }
}
