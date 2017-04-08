#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_framerate.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <iostream>
#include <memory>
#include <map>
#include <string>
#include "../utils/logging.h"
#include "../2d/sprite.h"
#include "../2d/scene.h"
#include "../controllers/keyboard.h"
#include "../base/config.h"
#include "../base/macros.h"
#include "../base/sdl.h"

NS_HC_BEGIN

using std::unique_ptr;
using std::map;
using std::string;

class Game {
public:
  Game(GameConfig config) : config_(config), window_(nullptr){};
  ~Game(){
    IMG_Quit();
    SDL_Quit();
  };

  bool init();

  void render();
  void update(){};
  void handleEvents();
  void clean();

  void loadScene(SceneUPtr scene);
  void runScene(SceneUPtr scene);

  SDL_Renderer *getRenderer() { return &*this->renderer_; }

  bool running() { return this->running_; }

private:
  GameConfig config_;
  FPSmanager fpsManager_;
  SceneUPtr scene_;
  bool running_;

  WindowUPtr window_;
  RendererSPtr renderer_;

  void executeScene();
  void loop();
  void processScene();
};

NS_HC_END
