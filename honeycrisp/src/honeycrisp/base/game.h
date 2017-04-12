#pragma once

#include "../2d/scene.h"
#include "../base/game_config.h"
#include "../base/macros.h"
#include "../base/timer.h"
#include "game_context.h"

NS_HC_BEGIN

class hcGame {
public:
  hcGame(hcGameConfig config) : config_(config) {};
  ~hcGame() {
    IMG_Quit();
    SDL_Quit();
  };

  bool init();

  void render();
  void update();
  void handleEvents();
  void clean();

  void loadScene(SceneUPtr scene);
  void run();

  bool running() { return this->running_; }

private:
  hcGameConfig config_;
  hcTimer fpsTimer;
  hcTimer capTimer;
  SceneUPtr scene_;
  bool running_;

  Base::hcGameContext gameContext;

  void executeScene();
  void loop();
  void processScene();
};

NS_HC_END
