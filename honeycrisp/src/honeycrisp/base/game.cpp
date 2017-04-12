#include "game.h"
#include "../controllers/keyboard.h"
#include <assert.h>

USING_NS_HC;

bool hcGame::init() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    LOG(SDL_GetError());
    return false;
  }
  if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0) {
    LOG(SDL_GetError());
    return false;
  }
  if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
    LOG(SDL_GetError());
    return false;
  }
  this->gameContext.window = make_unique_window(this->config_.title, this->config_.xpos,
                                     this->config_.ypos, this->config_.width,
                                     this->config_.height, this->config_.flags);
  if (this->gameContext.window == nullptr) {
    LOG(SDL_GetError());
    SDL_Quit();
    return false;
  }

  auto numGamepads = SDL_NumJoysticks();
  if (numGamepads > 0) {
    for (int i = 0; i < numGamepads; i++) {
      auto joystick = SDL_JoystickOpen(i);
      if (joystick == NULL) {
        LOG("FAILURE TO LOAD GAMEPAG");
        return false;
      }
      this->gameContext.gamepads.push_back(new Controllers::Gamepad(joystick));
    }
  }

  this->gameContext.keyboard = new Controllers::Keyboard();

  this->gameContext.renderer = make_shared_renderer(
      this->gameContext.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (this->gameContext.renderer == nullptr) {
    LOG(SDL_GetError());
    SDL_Quit();
    return false;
  }
  SDL_SetRenderDrawColor(&*this->gameContext.renderer, 255, 255, 255, 255);

  this->running_ = true;
  return true;
}

void hcGame::update() { this->scene_->update(); }

void hcGame::render() {
  SDL_RenderClear(&*this->gameContext.renderer);
  this->processScene();
  SDL_RenderPresent(&*this->gameContext.renderer);
}

void hcGame::handleEvents() {
  SDL_Event event;
  if (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      this->running_ = false;
      break;
    default:
      break;
    }
  }
  this->gameContext.keyboard->update();
}

void hcGame::loadScene(SceneUPtr scene) { this->scene_ = move(scene); }

void hcGame::run() {
  this->executeScene();
}

void hcGame::executeScene() {
  this->scene_->attachGameContext(&this->gameContext);
  this->scene_->init();
  this->loop();
}

void hcGame::processScene() { this->scene_->render(); }

void hcGame::loop() {
  uint32_t countedFrames = 0;
  this->fpsTimer.start();
  const int ticksPerFrame = 1000 / this->config_.fps;
  while (this->running()) {
    this->capTimer.start();
    this->handleEvents();

    float avgFPS = countedFrames / (this->fpsTimer.getTicks() / 1000.f);
    if (avgFPS > 200000) {
      avgFPS = 0;
    }
    this->update();
    this->render();
    ++countedFrames;
    int frameTicks = capTimer.getTicks();
    if (frameTicks < ticksPerFrame) {
      SDL_Delay(ticksPerFrame - frameTicks);
    }
  }
}

void hcGame::clean() {
  //SDL_DestroyWindow(&*this->gameContext.window);
  //SDL_DestroyRenderer(&*this->gameContext.renderer);
  SDL_Quit();
}
