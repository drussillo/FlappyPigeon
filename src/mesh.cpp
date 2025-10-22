#include "mesh.h"

#include <vector>

Mesh::Mesh(const GLenum primitiveType,
           const std::vector<float> &vertices, 
           const std::vector<unsigned int> &attributeSizes,
           const std::vector<unsigned int> &indices)
           : primitiveType{primitiveType},
             vertices{vertices},
             attributeSizes{attributeSizes},
             indices{indices} {
  if(vertices.empty()) {
    std::cerr << "Error: attempting to construct mesh without vertices" << std::endl;
  }
  if(attributeSizes.empty()) {
    std::cerr << "Error: attempting to construct mesh without attributes" << std::endl;
  }
  for(unsigned int size : attributeSizes) {
    vertexAttributes += size;
  }
  if(vertexAttributes > vertices.size()) {
    std::cerr << "Error: more attributes than actual data in vertices" << std::endl;
  }
  vertexCount = vertices.size() / vertexAttributes;
}


void Mesh::genBuffers() {
  glGenVertexArrays(1, &VAO);
  if(!indices.empty()) {
    glGenBuffers(1, &EBO);
  }
  glGenBuffers(1, &VBO);
}

void Mesh::upload() {
  glBindVertexArray(VAO);
  if(EBO != 0) {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
  }
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
  // TODO
  // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
  // glEnableVertexAttribArray(0);
  // glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));
  // glEnableVertexAttribArray(1);
  // glBindVertexArray(0);
}


void Mesh::bindVAO() {
  glBindVertexArray(VAO);
}

void Mesh::unbindVAO() {
  glBindVertexArray(0);
}

