#include "shader.h"

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <fstream>
#include <memory>
#include <unordered_map>

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

void Shader::setMat4UniformLocation(const std::string &uniformName) {
  use();
  int newLocation = glGetUniformLocation(program, uniformName.c_str());
  if(newLocation == -1) {
    std::cerr << "Warning: uniform allocation failed. " << std::endl;
  } else {
    mat4UniformLocations[uniformName] = newLocation;
  }
}

void Shader::setMat4Uniform(const std::string &uniformName, const glm::mat4 &uniformMatrix) {
  use();
  int uniformLocation;
  try {
    uniformLocation = mat4UniformLocations.at(uniformName);
  } catch(std::out_of_range &e) {
    std::cerr << "Uniform '" << uniformName << "' not found in active locations. \n" << e.what() << std::endl;
  }
  glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(uniformMatrix));
}

unsigned int Shader::getProgram() const {
  return program;
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

// links vertex and fragment shaders and clears strings
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



ProjectionUBO::~ProjectionUBO() {
  glDeleteBuffers(1, &UBO);
}


void ProjectionUBO::setProjectionMatrix(const glm::mat4 &newProjection) {
  projectionMatrix = newProjection;
}

void ProjectionUBO::genProjectionBuffer() {
  glGenBuffers(1, &UBO);
  glBindBuffer(GL_UNIFORM_BUFFER, UBO);
  glBufferData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), nullptr, GL_DYNAMIC_DRAW);
}


void ProjectionUBO::uploadProjection(const std::shared_ptr<Shader> shader) {
  glBindBuffer(GL_UNIFORM_BUFFER, UBO);
  glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(projectionMatrix));

  unsigned int blockIndex = glGetUniformBlockIndex(shader->getProgram(), "Matrices");
  glUniformBlockBinding(shader->getProgram(), blockIndex, 0);
  glBindBufferBase(GL_UNIFORM_BUFFER, 0, UBO);
}



/*
  glBindFramebuffer(GL_FRAMEBUFFER, fbo);
  glViewport(0, 0, 320, 180);
  projection = glm::ortho(0.0f, 320.0f, 0.0f, 180.0f, -1.0f, 1.0f);
??
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
  glViewport(0, 0, windowWidth, windowHeight);
  drawFullscreenQuad(fboTexture);
*/


