#ifndef MESH_H
#define MESH_H


#include <glad/glad.h>
#include <vector>


class Mesh {
public:
  Mesh(const std::vector<float> &vertices,
       const std::vector<unsigned int> &attributeSizes,
       const std::vector<unsigned int> &indices={},
       const GLenum primitiveType=GL_TRIANGLES);
  ~Mesh();

  GLenum getType() const;
  unsigned int getVertexCount() const;
  bool hasEBO() const;
  unsigned int getIndexCount() const;

  void genBuffers();  // generates VAO, EBO, and VBO without binding
  void upload();  // binds VAO, sends data to GPU, unbinds VAO

  void bindVAO() const;
  static void unbindVAO();

private:
  std::vector<float> vertices;
  std::vector<unsigned int> attributeSizes;
  std::vector<unsigned int> indices;
  GLenum primitiveType;
  unsigned int vertexCount = 0;
  unsigned int vertexAttributes = 0;
  unsigned int VAO = 0;
  unsigned int EBO = 0;
  unsigned int VBO = 0;
};


#endif
