#include "scenes/mode_infinite_scene.h"

#include <glm/glm.hpp>

#include "engine/resource_manager.h"
#include "elements/pigeon.h"
#include "elements/cloud.h"


ModeInfiniteScene::ModeInfiniteScene(ResourceManager &rm) : Scene(rm) {};


void ModeInfiniteScene::init() {
  backgroundColor = glm::vec4(0.6, 0.8, 1.0, 1.0);

  rm.loadTexture("pigeon", "sprites/pigeon_sprite.png", 12, 9, 4);
  rm.loadTexture("cloud_1", "sprites/cloud_1.png", 41, 16, 4);

  elements = {
    std::make_shared<Cloud>(rm),
    std::make_shared<Pigeon>(rm)
  };
}

void ModeInfiniteScene::exit() {
  rm.unloadTexture("pigeon");
  rm.unloadTexture("cloud_1");
}
