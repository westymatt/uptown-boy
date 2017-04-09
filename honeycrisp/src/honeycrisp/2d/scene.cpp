#include "scene.h"
#include "../utils/logging.h"

using std::for_each;

USING_NS_HC;

void Scene::addChild(Node *node) {
  node->setRenderer(this->renderer);
  this->nodes_.push_back(node);
}

bool Scene::init() { return true; }

void Scene::execute() {}

void Scene::setRenderer(RendererSPtr renderer) { this->renderer = renderer; }

void Scene::render() {
  for (Node *node : this->nodes_) {
    node->render();
  }
}
