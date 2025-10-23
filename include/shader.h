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

  void compile();
  void link();

  void setMat4(const std::string *variableName, const glm::mat4 &matrix) const;
  void use() const;
  static void unbind();

private:
  unsigned int program;
  unsigned int vertexShader;
  unsigned int fragmentShader;
  std::string vertexShaderSource;
  std::string fragmentShaderSource;
};


#endif
