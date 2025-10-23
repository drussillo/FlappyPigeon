#include "shader.h"

#include <glad/glad.h>
#include <iostream>
#include <fstream>

Shader::Shader(const std::string &vertexPath,
               const std::string &fragmentPath) {
  setVertexSource(vertexPath);
  setFragmentSource(fragmentPath);
}

void Shader::setVertexSource(const std::string &vertexPath) {
  std::string line;
  std::string text;
  std::ifstream file(vertexPath);
  while(std::getline(file, line)) {
    text += line + '\n';
  }
  vertexShaderSource = text;
}

void Shader::setFragmentSource(const std::string &fragmentPath) {
  std::string line;
  std::string text;
  std::ifstream file(fragmentPath);
  while(std::getline(file, line)) {
    text += line + '\n';
  }
  fragmentShaderSource = text;
}


unsigned int compileHelper(const GLenum shaderType, const std::string &source) {
  unsigned int shader = glCreateShader(shaderType);
  const char *sourceC = source.c_str();
  glShaderSource(shader, 1, &sourceC, nullptr);
  glCompileShader(shader);
  int success;
  char log[512];
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if(!success) {
    glGetShaderInfoLog(shader, 512, nullptr, log);
    std::cerr << "Shader compilation failed.\n" << log << std::endl;
  }
  return shader;
}

void Shader::compile() {
  vertexShader = compileHelper(GL_VERTEX_SHADER, vertexShaderSource);
  fragmentShader = compileHelper(GL_FRAGMENT_SHADER, fragmentShaderSource);
}

void Shader::link() {
  program = glCreateProgram();
  glAttachShader(program, vertexShader);
  glAttachShader(program, fragmentShader);
  glLinkProgram(program);
  int success;
  char log[512];
  glGetProgramiv(program, GL_LINK_STATUS, &success);
  if(!success) {
    glGetProgramInfoLog(program, 512, nullptr, log);
    std::cerr << "Program linking failed.\n" << log << std::endl;
  }
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
  vertexShaderSource.clear();
  fragmentShaderSource.clear();
}
