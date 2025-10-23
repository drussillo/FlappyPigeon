#include "element.h"

#include <vector>
#include "mesh.h"
#include "shader.h"


Element::Element(std::shared_ptr<Mesh> mesh,
                 std::shared_ptr<Shader> shader)
                 : mesh{mesh},
                   shader{shader} {}

void Element::update() {
  position += velocity; // * deltaTime
}

