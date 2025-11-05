#include "shader.h"

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <fstream>

Shader::Shader(const std::string &vertexPath,
               const std::string &fragmentPath) {
  setVertexSource(vertexPath);
  setFragmentSource(fragmentPath);
}

Shader::~Shader() {
  unbind();
  glDeleteProgram(program);
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

void Shader::setTransformLocation(const std::string &transformName) {
  transformLocation = glGetUniformLocation(program, transformName.c_str());
  if(transformLocation == -1) {
    std::cerr << "Warning: transform location failed " << std::endl;
  }
}

void Shader::setTransform(const glm::mat4 &transformMatrix) {
  glUniformMatrix4fv(transformLocation, 1, GL_FALSE, glm::value_ptr(transformMatrix));
}

static unsigned int compileHelper(const GLenum shaderType, const char *source) {
  unsigned int shader = glCreateShader(shaderType);
  glShaderSource(shader, 1, &source, nullptr);
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
  vertexShader = compileHelper(GL_VERTEX_SHADER, vertexShaderSource.c_str());
  fragmentShader = compileHelper(GL_FRAGMENT_SHADER, fragmentShaderSource.c_str());
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

void Shader::use() const {
  glUseProgram(program);
}

void Shader::unbind() {
  glUseProgram(0);
}

