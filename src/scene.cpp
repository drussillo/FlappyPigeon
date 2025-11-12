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


void Scene::setBackgroundColor(const glm::vec4 &newBackgroundColor) {
  backgroundColor = newBackgroundColor;
}

void Scene::addElement(std::shared_ptr<Element> newElement) {
  elements.push_back(newElement);
}


void Scene::render() const {
  glClearColor(backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
  glClear(GL_COLOR_BUFFER_BIT);
  for(std::shared_ptr<Element> element : elements) {
    element->update();
    element->applyModel();
    element->draw();
  }
}
