#include "main_menu_scene.h"

#include <glm/glm.hpp>
#include <memory>
#include <vector>

#include "resource_manager.h"
#include "shader.h"
#include "mesh.h"
#include "element.h"
#include "pigeon.h"


MainMenuScene::MainMenuScene(ResourceManager &rm) : Scene(rm) {};


void MainMenuScene::init() {
  // backgroundColor = glm::vec4(0.6, 0.8, 1.0, 1.0);

  rm.loadMesh(
    "quad",
    { 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f,    // top left
      0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,    // bottom left
      1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,    // top right
      1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f },  // bottom right
    {3, 4},
    { 0, 1, 2,
      2, 1, 3 }
  );

  rm.loadShader(
    "defaultShader",
    "shaders/basicShaderTransform.vert", 
    "shaders/basicShader.frag"
  );
  rm.getShader("defaultShader")->setMat4UniformLocation("transform");

  elements = {
    std::make_shared<Pigeon>(rm.getMesh("quad"), rm.getShader("defaultShader"))
  };
}

