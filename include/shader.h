#ifndef SHADER_H
#define SHADER_H


class Shader {
public:
  Shader(const std::string &vertexPath="", const std::string &fragmentPath="");

  void setVertexSource(const std::string &vertexPath);
  void setFragmentSource(const std::string &fragmentPath);

  void compile();
  void link();
  void use();

private:
  unsigned int program;
  unsigned int vertexShader;
  unsigned int fragmentShader;
  std::string vertexShaderSource;
  std::string fragmentShaderSource;
};


#endif
