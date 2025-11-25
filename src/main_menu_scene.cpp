#include "main_menu_scene.h"

#include <glm/glm.hpp>
#include <memory>
#include <vector>

#include "resource_manager.h"
#include "pigeon.h"


MainMenuScene::MainMenuScene(ResourceManager &rm) : Scene(rm) {};


void MainMenuScene::init() {
  backgroundColor = glm::vec4(0.6, 0.8, 1.0, 1.0);

  rm.loadTexture("Pigeon", "sprites/pigeon_sprite.png", 12, 9, 4);

  elements = {
    std::make_shared<Pigeon>(rm)
  };
}

void MainMenuScene::exit() {
  rm.unloadTexture("Pigeon");
}
