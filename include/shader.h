#ifndef SHADER_H
#define SHADER_H

#include <glm/glm.hpp>

#include <string>
#include <memory>
#include <unordered_map>

class Shader {
public:
  Shader(const std::string &vertexPath="", const std::string &fragmentPath="");
  ~Shader();

  void setVertexSource(const std::string &vertexPath);
  void setFragmentSource(const std::string &fragmentPath);
  void setMat4UniformLocation(const std::string &uniformName);
  void setMat4Uniform(const std::string &uniformName, const glm::mat4 &uniformMatrix=glm::mat4(1.0f));
  unsigned int getProgram() const;

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
namespace ShaderUtils {

void genProjectionBuffer();
void setProjection(glm::mat4 newProjection);
void uploadProjection();

}


class ProjectionUBO {
public:
  ProjectionUBO() = default;
  ~ProjectionUBO();
  
  void setProjectionMatrix(const glm::mat4 &newProjection);
  void genProjectionBuffer();
  void uploadProjection(const std::shared_ptr<Shader> shader);

private:
  unsigned int UBO;
  glm::mat4 projectionMatrix;
};


#endif
