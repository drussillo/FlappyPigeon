#ifndef TEXTURE_H
#define TEXTURE_H


#include <string>


class Texture {
public:
  Texture(const std::string &path, int width, int height, int nrChannels);
  ~Texture();

  unsigned int getID();

  void generate();
  void load();

private:
  std::string path;
  unsigned char *data;
  unsigned int texture;
  int width;
  int height;
  int nrChannels;
};


#endif
