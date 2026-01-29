#include "engine/game.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "engine/scene_manager.h"
#include "engine/resource_manager.h"
#include "scenes/scene_names.h"


Game::Game() : rm(), sm(rm) {}


void Game::init() {
  rm.loadMesh(
    "quad",
    // TODO: build function to overwrite UVs !vvv! for textures (normalized).
    { 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,    // bottom left
      0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,    // top left
      1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,    // top right
      1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f },  // bottom right
    {2, 4, 2},
    { 1, 0, 2,
      2, 0, 3 }
  );

  rm.loadShader(
    "defaultShader",
    "shaders/defaultShader.vert", 
    "shaders/defaultShader.frag"
  );
  rm.getShader("defaultShader")->setMat4UniformLocation("uTransform");

  // upload UBO
  resolution = glm::vec2(160.0f, 90.0f);
  projection.setProjectionMatrix(glm::ortho(0.0f, resolution.x, 0.0f, resolution.y));
  projection.genProjectionBuffer();
  projection.uploadProjection(rm.getShader("defaultShader"));

  sm.changeScene(SceneNames::MODE_INFINITE);
  // sm.changeScene(SceneNames::MAIN_MENU);
}

void Game::mainLoop(GLFWwindow *window) {
  float dt = 1.0;
  // TODO: add deltatime calculation logic


  while(!glfwWindowShouldClose(window)) {
    sm.updateCurrent(dt);
    sm.renderCurrent();
    sm.changeSceneToNext();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
}

