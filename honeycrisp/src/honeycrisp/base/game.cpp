#include "../controllers/keyboard.h"
#include "game.h"

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
  this->window_ = make_unique_window(
      this->config_.title, this->config_.xpos, this->config_.ypos,
      this->config_.width, this->config_.height, this->config_.flags);
  if (this->window_ == nullptr) {
    LOG(SDL_GetError());
    SDL_Quit();
    return false;
  }
  
  auto numGamepads = SDL_NumJoysticks();
  if (numGamepads > 0) {
    for (int i = 0; i < numGamepads; i++) {
       auto joyStick = SDL_JoystickOpen(i);
       if (joyStick == NULL) {
         LOG("FAILURE TO LOAD GAMEPAG");
         return false;
       }
       this->gamepads_.push_back(joyStick);
    }
  }
  
  this->keyboard_ = new Controllers::Keyboard();

  this->renderer_ = make_shared_renderer(
      this->window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (this->renderer_ == nullptr) {
    LOG(SDL_GetError());
    SDL_Quit();
    return false;
  }
  SDL_SetRenderDrawColor(&*this->renderer_, 255, 255, 255, 255);

  SDL_initFramerate(&this->fpsManager_);
  SDL_setFramerate(&this->fpsManager_, this->config_.fps);
  SDL_framerateDelay(&this->fpsManager_);
  log(SDL_getFramerate(&this->fpsManager_));
  this->running_ = true;
  return true;
}

void hcGame::update() {
  this->scene_->update();
}

void hcGame::render() {
  SDL_RenderClear(&*this->renderer_);
  this->processScene();
  SDL_RenderPresent(&*this->renderer_);
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
  this->keyboard_->update();
}

void hcGame::loadScene(SceneUPtr scene) { this->scene_ = move(scene); }

void hcGame::runScene(SceneUPtr scene) {
  this->scene_ = move(scene);
  this->executeScene();
}

void hcGame::executeScene() {
  this->scene_->setRenderer(this->renderer_);
  this->scene_->init();
  this->loop();
}

void hcGame::processScene() { this->scene_->render(); }

void hcGame::loop() {
  while (this->running()) {
    this->handleEvents();
    this->update();
    this->render();
    SDL_framerateDelay(&this->fpsManager_);
  }
}

void hcGame::clean() {
  SDL_DestroyWindow(&*this->window_);
  SDL_DestroyRenderer(&*this->renderer_);
  SDL_Quit();
}
