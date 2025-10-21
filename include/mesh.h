#ifndef MESH_H
#define MESH_H

#include <vector>

class Mesh {
public:
  Mesh(const GLenum primitiveType=GL_TRIANGLES,
       const std::vector<float> &vertices, 
       const std::vector<unsigned int> &attributeSizes,
       const std::vector<unsigned int> &indices={});

  void genBuffers();  // generates VAO, EBO, and VBO without binding
  void upload();  // binds VAO, sends data to GPU, unbinds VAO

  void bindVAO() const;
  void unbindVAO() const;

private:
  GLenum primitiveType;
  std::vector<float> vertices;
  std::vector<unsigned int> attributeSizes;
  std::vector<unsigned int> indices;
  unsigned int vertexCount = 0;
  unsigned int vertexAttributes = 0;
  unsigned int VAO = 0;
  unsigned int EBO = 0;
  unsigned int VBO = 0;
};

#endif
