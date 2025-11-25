#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "engine/resource_manager.h"
#include "engine/scene_manager.h"

class Game {
public:
  Game();
  
  void init();  // load initial scene
  void mainLoop(GLFWwindow *window);  // pass resources to scenes (will use for current scene)

private:
  glm::vec2 resolution;
  ProjectionUBO projection;
  ResourceManager rm;
  SceneManager sm;
};


#endif
