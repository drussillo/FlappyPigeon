#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>

class Element {
public:
  Element(std::vector<float> &input);

private:
  std::vector<float> vertices;
  unsigned int VBO;
  unsigned int VAO;
  unsigned int EBO;
  // Shader shader;
}

#endif // !ELEMENT_H
