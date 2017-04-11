#include "scene.h"
#include "../utils/logging.h"

using std::for_each;

USING_NS_HC;

void Scene::addChild(Node *node) {
  node->setRenderer(this->gc->renderer);
  this->nodes_.push_back(node);
}

void Scene::execute() {}

void Scene::attachGameContext(Base::hcGameContext *gameContext) { this->gc = gameContext; }

void Scene::render() {
  for (Node *node : this->nodes_) {
    node->render();
  }
}
