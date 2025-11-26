#ifndef ELEMENT_H
#define ELEMENT_H


#include <glm/glm.hpp>
#include <memory>

#include "graphics/mesh.h"
#include "graphics/shader.h"
#include "graphics/texture.h"

class Element {
public:
  Element(const std::shared_ptr<Mesh> mesh,
          const std::shared_ptr<Shader> shader,
          const std::shared_ptr<Texture> textue);

  void setPosition(glm::vec2 newPosition);
  void setVelocity(glm::vec2 newVelocity);
  void addVelocity(glm::vec2 newVelocity);
  void setRotation(float newRotation);
  void setScale(glm::vec2 newScale);

  void applyModel();
  virtual void draw();
  virtual void update(float dt);
  virtual bool collidesWith(std::shared_ptr<Element> element);

protected:
  std::shared_ptr<Mesh> mesh;
  std::shared_ptr<Shader> shader;
  std::shared_ptr<Texture> texture;
  glm::vec2 velocity = glm::vec2(0.0f, 0.0f);
  glm::vec2 position = glm::vec2(0.0f, 0.0f);  // transformation
  float rotation = 0.0f;  // in degrees (convert to radians later)
  glm::vec2 scale = glm::vec2(1.0f, 1.0f);  // wscale, hscale
  glm::mat4 model = glm::mat4(1.0f);  // translation * rotation * scale, identity matrix by default
};


#endif
