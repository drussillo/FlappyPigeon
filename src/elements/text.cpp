#include "elements/text.h"


Text::Text(ResourceManager &rm) : 
  Element(rm.getMesh("quad"), rm.getShader("defaultShader"), nullptr) {}


