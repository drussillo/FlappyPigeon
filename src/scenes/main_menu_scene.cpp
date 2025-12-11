#include "scenes/main_menu_scene.h"

#include "glm/glm.hpp"


MainMenuScene::MainMenuScene(ResourceManager &rm) : Scene(rm) {}

void MainMenuScene::init() {
  setBackgroundColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
}

void MainMenuScene::exit() {}


void MainMenuScene::update(float dt) {
  Scene::update(dt);
}

