#include "graphics/texture.h"

#include <iostream>

#include <glad/glad.h>
#include <stb/stb_image.h>


Texture::Texture(const std::string &path, int width, int height, int nrChannels) : 
  path{path}, width{width}, height{height}, nrChannels{nrChannels} {}

Texture::~Texture() {
  stbi_image_free(data);
}


void Texture::generate() {
  glGenTextures(1, &texture);
}

void Texture::load() {
  glBindTexture(GL_TEXTURE_2D, texture);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
  if(data) {
    if(nrChannels == 4) {
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    } else {
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    }
    glGenerateMipmap(GL_TEXTURE_2D);
  } else {
    std::cerr << "Error: failed to load texture" << std::endl;
  }
}

void Texture::bindUnit(const unsigned int shaderProgram) {
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, texture);
  glUniform1i(glGetUniformLocation(shaderProgram, "texture1"), 0);
}
