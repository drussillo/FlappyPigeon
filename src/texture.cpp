#include "texture.h"

#include <glad/glad.h>
#include <stb/stb_image.h>
#include <iostream>
#include <string>

Texture::Texture(const std::string &path, int width, int height, int nrChannels) : 
  path{path}, width{width}, height{height}, nrChannels{nrChannels} {}

Texture::~Texture() {
  stbi_image_free(data);
}


unsigned int Texture::getID() {
  return texture;
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
    printf("%s\n", data);
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
