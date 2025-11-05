#include "mesh.h"

#include <iostream>
#include <vector>

Mesh::Mesh(
           const std::vector<float> &vertices, 
           const std::vector<unsigned int> &attributeSizes,
           const std::vector<unsigned int> &indices,
           const GLenum primitiveType)
           : vertices{vertices},
             attributeSizes{attributeSizes},
             indices{indices},
             primitiveType{primitiveType} {
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

Mesh::~Mesh() {
  unbindVAO();
  glDeleteBuffers(1, &VAO);
  glDeleteBuffers(1, &EBO);
  glDeleteBuffers(1, &VBO);
}


GLenum Mesh::getType() const {
  return primitiveType;
}

unsigned int Mesh::getVertexCount() const {
  return vertexCount;
}

bool Mesh::hasEBO() const {
  return !indices.empty();
}

unsigned int Mesh::getIndexCount() const {
  return indices.size();
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
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
  }
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_DYNAMIC_DRAW);

  size_t stride = 0;
  for(size_t size : attributeSizes) {
    stride += size;
  }
  size_t offset = 0;
  for(size_t i = 0; i < attributeSizes.size(); i++) {
    glVertexAttribPointer(i,
                          attributeSizes[i], 
                          GL_FLOAT, 
                          GL_FALSE, 
                          stride * sizeof(float), 
                          (void*)(offset * sizeof(float)));
    glEnableVertexAttribArray(i);
    offset += attributeSizes[i];
  }
  glBindVertexArray(0);
}


void Mesh::bindVAO() const {
  glBindVertexArray(VAO);
}

void Mesh::unbindVAO() {
  glBindVertexArray(0);
}

