#pragma once

#include "../2d/scene.h"
#include "../2d/sprite.h"
#include "../base/game_config.h"
#include "../base/macros.h"
#include "../base/sdl.h"
#include "../controllers/keyboard.h"
#include "../utils/logging.h"
#include "game_context.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL2_framerate.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

NS_HC_BEGIN

using std::unique_ptr;
using std::map;
using std::string;
using std::vector;

class hcGame {
public:
  hcGame(hcGameConfig config) : config_(config), window_(nullptr){};
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
  void runScene(SceneUPtr scene);

  SDL_Renderer *getRenderer() { return &*this->renderer_; }

  bool running() { return this->running_; }

private:
  hcGameConfig config_;
  FPSmanager fpsManager_;
  SceneUPtr scene_;
  bool running_;

  WindowUPtr window_;
  RendererSPtr renderer_;

  /*
   * Input Devices
   */
  vector<SDL_Joystick *> gamepads_;
  Controllers::Keyboard *keyboard_;

  Base::hcGameContext gameContext;

  void executeScene();
  void loop();
  void processScene();
};

NS_HC_END
