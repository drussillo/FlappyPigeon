#ifndef SHADER_H
#define SHADER_H

#include <glm/glm.hpp>

#include <string>

class Shader {
public:
  Shader(const std::string &vertexPath="", const std::string &fragmentPath="");
  ~Shader();

  void setVertexSource(const std::string &vertexPath);
  void setFragmentSource(const std::string &fragmentPath);
  void setTransformLocation(const std::string &transformName="transform");
  void setTransform(const glm::mat4 &transformMatrix=glm::mat4(1.0f));

  void compile();
  void link();

  void use() const;
  static void unbind();

private:
  unsigned int program;
  unsigned int vertexShader;
  unsigned int fragmentShader;
  int transformLocation;
  std::string vertexShaderSource;
  std::string fragmentShaderSource;
};


#endif
