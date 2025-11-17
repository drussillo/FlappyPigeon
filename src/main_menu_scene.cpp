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
  std::shared_ptr<Shader> basicShader = std::make_shared<Shader>(
    "shaders/basicShaderTransform.vert", 
    "shaders/basicShader.frag"
  );
  basicShader->compile();
  basicShader->link();
  
  // TODO
  // std::shared_ptr<Mesh> quad = std::make_shared<Mesh>(
  //   std::vector<float>{
  //     1.0f, 1.0f,
  //   }
  // );
}

