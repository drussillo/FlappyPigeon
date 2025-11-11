#ifndef PIGEON_H
#define PIGEON_H

#include "element.h"

#include <memory>

class Pigeon : public Element {
public:
  Pigeon(std::shared_ptr<Mesh> mesh,
         std::shared_ptr<Shader> shader);
  virtual ~Pigeon() = default;

  void update() override;
};


#endif
