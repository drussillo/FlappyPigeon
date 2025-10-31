#include <glm/glm.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <memory>

#include "mesh.h"
#include "shader.h"
#include "element.h"
#include "scene.h"


int main() {
  /*****************************************************************/
  // Initialize GLFW
  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW\n";
    return -1;
  }

  // Set OpenGL version and profile (3.3 core)
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  /*****************************************************************/
  // create window and initialize glad
  int res_w = 1920;
  int res_h = 1080;
  bool fullscreen = true;

  GLFWmonitor* monitor = fullscreen ? glfwGetPrimaryMonitor() : nullptr;

  // Create a window
  GLFWwindow* window = glfwCreateWindow(res_w, res_h, "FlappyPigeon", monitor, nullptr);
  if (!window) {
    std::cerr << "Failed to create GLFW window\n";
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  // Load OpenGL function pointers using GLAD
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
      std::cerr << "Failed to initialize GLAD\n";
      return -1;
  }

  /*****************************************************************/
  // create elements
  std::shared_ptr<Mesh> triangleMesh = std::make_shared<Mesh>(
    std::vector<float>{
      0.0f, 0.5f,
      -0.5f, -0.5f,
      0.5f, -0.5f},
    std::vector<unsigned int>{
      2});
  triangleMesh->genBuffers();
  triangleMesh->upload();

  std::shared_ptr<Mesh> quadMesh = std::make_shared<Mesh>(
    std::vector<float>{
      -0.5f, 0.5f,
      -0.5f, -0.5f,
      0.5f, 0.5f,
      0.5f, -0.5f},
    std::vector<unsigned int>{
      2},
    std::vector<unsigned int>{
      0, 1, 2,
      2, 1, 3});
  quadMesh->genBuffers();
  quadMesh->upload();

  std::shared_ptr<Shader> basicShader = std::make_shared<Shader>(
    "shaders/basicShader.vert",
    "shaders/basicShader.frag");
  basicShader->compile();
  basicShader->link();

  std::shared_ptr<Shader> basicShaderTransform = std::make_shared<Shader>(
    "shaders/basicShaderTransform.vert",
    "shaders/basicShader.frag");
  basicShaderTransform->compile();
  basicShaderTransform->link();
  basicShaderTransform->use();
  basicShaderTransform->setTransformLocation();
  Shader::unbind();

  std::shared_ptr<Element> t1 = std::make_shared<Element>(
    triangleMesh,
    basicShaderTransform);

  std::shared_ptr<Element> q1 = std::make_shared<Element>(
    quadMesh,
    basicShader);

  Scene testscene{
    {t1}, 
    glm::vec4(0.6, 0.8, 1.0, 1.0)};


  /*****************************************************************/

  glViewport(0, 0, res_w, res_h);
  /*****************************************************************/
  // main loop
  while (!glfwWindowShouldClose(window)) {
    /*****************************************/

    testscene.render();

    /*****************************************/
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // Clean up
  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
