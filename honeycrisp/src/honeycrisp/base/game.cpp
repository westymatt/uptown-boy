#include "game.h"

USING_NS_HC;

bool Game::init() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    LOG(SDL_GetError());
    return false;
  }
  if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0) {
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

void Game::render() {
  SDL_RenderClear(&*this->renderer_);
  this->processScene();
  SDL_RenderPresent(&*this->renderer_);
}

void Game::handleEvents() {
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
  Keyboard::update();
}

void Game::loadScene(SceneUPtr scene) { this->scene_ = move(scene); }

void Game::runScene(SceneUPtr scene) {
  this->scene_ = move(scene);
  this->executeScene();
}

void Game::executeScene() {
  this->scene_->setRenderer(this->renderer_);
  this->scene_->init();
  this->loop();
}

void Game::processScene() { this->scene_->render(); }

void Game::loop() {
  while (this->running()) {
    this->handleEvents();
    this->scene_->enterFrame();
    this->update();
    this->render();
    this->scene_->exitFrame();
    SDL_framerateDelay(&this->fpsManager_);
  }
}

void Game::clean() {
  SDL_DestroyWindow(&*this->window_);
  SDL_DestroyRenderer(&*this->renderer_);
  SDL_Quit();
}
