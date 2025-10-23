#include "element.h"

#include <glad/glad.h>
#include <vector>

#include "mesh.h"
#include "shader.h"


Element::Element(std::shared_ptr<Mesh> mesh,
                 std::shared_ptr<Shader> shader)
                 : mesh{mesh},
                   shader{shader} {}


void Element::draw() const {
  shader->use();
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
  position += velocity; // * deltaTime
}

