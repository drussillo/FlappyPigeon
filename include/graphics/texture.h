#ifndef TEXTURE_H
#define TEXTURE_H


#include "glm/glm.hpp"
#include <string>


class Texture {
public:
  Texture(const std::string &path, int width, int height, int nrChannels, const glm::vec2 &uvCoords);
  ~Texture();

  void generate();
  void load();
  void bindUnit(const unsigned int shaderProgram);

private:
  std::string path;
  unsigned char *data;
  unsigned int texture;
  int width;
  int height;
  int nrChannels;
  glm::vec2 uvCoords;
};


#endif
