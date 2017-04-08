#pragma once

#include "SDL2/SDL.h"
#include <vector>
#include "node.h"
#include "../base/sdl.h"

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
  virtual void setRenderer(RendererSPtr renderer);
  virtual void enterFrame();
  virtual void exitFrame();
  virtual ~Scene(){};

protected:
  vector<Node *> nodes_;
  RendererSPtr renderer;
};

using SceneUPtr = unique_ptr<Scene>;
using SceneSPtr = shared_ptr<Scene>;

NS_HC_END
