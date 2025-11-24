#include "element.h"

#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include <iostream>

#include "mesh.h"
#include "shader.h"
#include "texture.h"


Element::Element(const std::shared_ptr<Mesh> mesh,
                 const std::shared_ptr<Shader> shader,
                 const std::shared_ptr<Texture> texture)
                 : mesh{mesh},
                   shader{shader},
                   texture{texture} {}


void Element::setPosition(glm::vec2 newPosition) {
  position = newPosition;
}

void Element::setVelocity(glm::vec2 newVelocity) {
  velocity = newVelocity;
}

void Element::addVelocity(glm::vec2 newVelocity) {
  velocity += newVelocity;
}

void Element::setRotation(float newRotation) {
  rotation = newRotation;
}

void Element::setScale(glm::vec2 newScale) {
  scale = newScale;
}


// applies model and uploads to uniform
void Element::applyModel() {
  model = glm::mat4(1.0);
  model = glm::translate(model, glm::vec3(position.x, position.y, 0.0f));
  model = glm::rotate(model, glm::radians(rotation), glm::vec3(0, 0, 1));
  model = glm::scale(model, glm::vec3(scale.x, scale.y, 1));
  shader->setMat4Uniform("uTransform", model);
}

void Element::draw() const {
  shader->use();
  mesh->bindVAO();
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, texture->getID());
  glUniform1i(glGetUniformLocation(shader->getProgram(), "texture1"), 0);
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

void Element::update(float dt) {
  position += velocity * dt;
}

