#include "game.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "scene_manager.h"
#include "resource_manager.h"
#include "scene_names.h"


Game::Game() : rm(), sm(rm) {}


void Game::init() {
  sm.changeScene(SceneNames::MAIN_MENU);
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

