#include "element.h"

#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <vector>

#include "mesh.h"
#include "shader.h"


Element::Element(std::shared_ptr<Mesh> mesh,
                 std::shared_ptr<Shader> shader)
                 : mesh{mesh},
                   shader{shader} {}


void Element::setPosition(glm::vec2 newPosition) {
  position = newPosition;
}

void Element::setVelocity(glm::vec2 newVelocity) {
  velocity = newVelocity;
}

void Element::addVelocity(glm::vec2 newVelocity) {
  velocity += newVelocity;
}


void Element::applyModel() {
  model = glm::mat4(1.0);
  model = glm::translate(model, glm::vec3(position.x, position.y, 0.0f));
  model = glm::rotate(model, glm::radians(rotation), glm::vec3(0, 0, 1));
  model = glm::scale(model, glm::vec3(scale.x, scale.y, 1));
  shader->setTransform(model);
}

void Element::draw() const {
  shader->use();
  shader->setTransform(model);
  mesh->bindVAO();
  if(mesh->hasEBO()) {
    glDrawElements(
      mesh->getType(),
      mesh->getIndexCount(),
      GL_UNSIGNED_INT,  // EBO member type
      0  // Start at index 0 of EBO
    );
  } else {
    glDrawArrays(
      mesh->getType(),
      0,  // first index to be drawn
      mesh->getVertexCount()  // how many vertices
    );
  }
}

void Element::update() {
  velocity.y -= 0.000981f;
  if(position.y < -0.5f) velocity.y = 0.04;
  rotation+=1.0f;
  scale.x += 0.001f;
  scale.y += 0.001f;

  position += velocity; // * deltaTime
}

