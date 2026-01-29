#include "scenes/mode_infinite_scene.h"

#include <glm/glm.hpp>
#include <memory>
#include <vector>
#include <iostream>

#include "engine/resource_manager.h"
#include "scenes/scene_names.h"
#include "elements/pigeon.h"
#include "elements/cloud.h"
#include "elements/wall.h"


ModeInfiniteScene::ModeInfiniteScene(ResourceManager &rm) : Scene(rm) {};


void ModeInfiniteScene::init() {
  backgroundColor = glm::vec4(0.6, 0.8, 1.0, 1.0);

  rm.loadTexture("pigeon", res::relPath("sprites/pigeon_sprite.png"), 12, 9, 4);
  rm.loadTexture("brick_wall", res::relPath("sprites/brick_wall.png"), 14, 90, 4);
  rm.loadTexture("cloud_1", res::relPath("sprites/cloud_1.png"), 41, 16, 4);


  elements = {
    std::make_shared<Cloud>(rm),
    std::make_shared<Cloud>(rm),
    std::make_shared<Cloud>(rm),
    std::make_shared<Cloud>(rm),
    std::make_shared<Cloud>(rm),
    std::make_shared<Cloud>(rm),
    std::make_shared<Cloud>(rm),
    std::make_shared<Wall>(rm, 1),
    std::make_shared<Wall>(rm, 2),
    std::make_shared<Wall>(rm, 3),
    std::make_shared<Wall>(rm, 4),
    std::make_shared<Pigeon>(rm)
  };
}

void ModeInfiniteScene::update(float dt) {
  Scene::update(dt);

  if(elements[7]->collidesWith(elements[11]) || 
     elements[8]->collidesWith(elements[11]) ||
     elements[9]->collidesWith(elements[11]) ||
     elements[10]->collidesWith(elements[11]) ||
     elements[11]->getPosition().y > 100 ||
     elements[11]->getPosition().y < -20) {
    nextScene = SceneNames::MODE_INFINITE;
    finished = true;
  }

  for(int i = 7; i < 11; i++) {
    if(elements[i]->getPosition().x < elements[11]->getPosition().x && !elements[i]->getPassed()) {
      elements[i]->setPassed(true);
      points++;
      // TODO: Add textelement and update.
      std::cout << points << std::endl;
    }
  }
}

void ModeInfiniteScene::exit() {
  rm.unloadTexture("pigeon");
  rm.unloadTexture("brick_wall");
  rm.unloadTexture("cloud_1");
}
