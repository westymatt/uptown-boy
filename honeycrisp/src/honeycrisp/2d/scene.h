#pragma once

#include "../base/sdl.h"
#include "../base/game_context.h"
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
  virtual bool init()=0;
  virtual void execute();
  virtual void render();
  virtual void update()=0;
  virtual void attachGameContext(Base::hcGameContext *gameContext);
  virtual ~Scene(){};

protected:
  Base::hcGameContext *gameContext;
  vector<Node *> nodes_;
};

using SceneUPtr = unique_ptr<Scene>;
using SceneSPtr = shared_ptr<Scene>;

NS_HC_END
