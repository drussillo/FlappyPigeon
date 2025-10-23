#ifndef ELEMENT_H
#define ELEMENT_H


#include <glm/glm.hpp>
#include <memory>

#include "mesh.h"
#include "shader.h"

class Element {
public:
  Element(std::shared_ptr<Mesh> mesh,
          std::shared_ptr<Shader> shader);

  void draw() const;
  void update();

private:
  std::shared_ptr<Mesh> mesh;
  std::shared_ptr<Shader> shader;
  glm::vec2 position = glm::vec2(0.0f, 0.0f);  // transformation
  glm::vec2 velocity = glm::vec2(0.0f, 0.0f);
  float rotation = 0.0f;  // in degrees (convert to radians later)
  glm::vec2 scale = glm::vec2(1.0f, 1.0f);  // wscale, hscale
  glm::mat3 model = glm::mat3(1.0f);  // translation * rotation * scale, identity matrix by default
};


#endif
