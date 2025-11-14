#ifndef SHADER_H
#define SHADER_H

#include <glm/glm.hpp>

#include <string>
#include <unordered_map>

class Shader {
public:
  Shader(const std::string &vertexPath="", const std::string &fragmentPath="");
  ~Shader();

  void setVertexSource(const std::string &vertexPath);
  void setFragmentSource(const std::string &fragmentPath);
  void setMat4UniformLocation(const std::string &uniformName);
  void setMat4Uniform(const std::string &uniformName, const glm::mat4 &uniformMatrix=glm::mat4(1.0f));

  void compile();
  void link();

  void use() const;
  static void unbind();

private:
  unsigned int program;
  unsigned int vertexShader;
  unsigned int fragmentShader;
  std::unordered_map<std::string, int> mat4UniformLocations;
  std::string vertexShaderSource;
  std::string fragmentShaderSource;
};

// TODO: add projection uniform UBO (uniform buffer object) ?


#endif
