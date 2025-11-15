#ifndef PIGEON_H
#define PIGEON_H

#include <memory>

#include "element.h"
#include "mesh.h"
#include "shader.h"

class Pigeon : public Element {
public:
  Pigeon(const std::shared_ptr<Mesh> mesh,
         const std::shared_ptr<Shader> shader);

  void update(float dt) override;

private:
  bool isJumping = false;
};


#endif
