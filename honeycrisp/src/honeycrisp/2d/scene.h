#pragma once

#include "../base/sdl.h"
#include "SDL2/SDL.h"
#include "node.h"
#include <vector>

using std::vector;
using std::unique_ptr;
using std::shared_ptr;

NS_HC_BEGIN

class Scene {
public:
  virtual void addChild(Node *node);
  virtual bool init();
  virtual void execute();
  virtual void render();
  virtual void update();
  virtual void setRenderer(RendererSPtr renderer);
  virtual ~Scene(){};

protected:
  vector<Node *> nodes_;
  RendererSPtr renderer;
};

using SceneUPtr = unique_ptr<Scene>;
using SceneSPtr = shared_ptr<Scene>;

NS_HC_END
