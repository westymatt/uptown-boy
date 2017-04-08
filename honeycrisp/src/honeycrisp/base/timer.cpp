#include "timer.h"
#include <SDL2/SDL.h>

USING_NS_HC;

void Timer::start() {
  this->started_ = true;
  this->paused_ = false;
  this->startTicks_ = SDL_GetTicks();
  this->pausedTicks_ = 0;
}

void Timer::stop() {
  this->started_ = false;
  this->paused_ = false;
  this->startTicks_ = 0;
  this->pausedTicks_ = 0;
}

void Timer::pause() {
  if (this->started_ && !this->paused_) {
    this->paused_ = true;

    this->pausedTicks_ = SDL_GetTicks() - this->startTicks_;
    this->startTicks_ = 0;
  }
}

void Timer::unpause() {
  if (this->started_ && this->paused_) {
    this->paused_ = false;
    this->startTicks_ = SDL_GetTicks() - this->pausedTicks_;
    this->pausedTicks_ = 0;
  }
}

bool Timer::isStarted() { return this->started_; }

bool Timer::isPaused() { return this->paused_ && this->started_; }

uint32_t Timer::getTicks() {
  uint32_t time = 0;
  if (this->started_) {
    if (this->paused_) {
      time = this->pausedTicks_;
    } else {
      time = SDL_GetTicks() - startTicks_;
    }
  }
  return time;
}
