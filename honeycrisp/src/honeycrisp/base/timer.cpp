#include "timer.h"
#include <SDL2/SDL.h>

USING_NS_HC;

hcTimer::hcTimer() {
  this->startTicks = 0;
  this->pausedTicks = 0;

  this->paused = false;
  this->started = false;
}

void hcTimer::start() {
  this->started = true;
  this->paused = false;
  this->startTicks = SDL_GetTicks();
  this->pausedTicks = 0;
}

void hcTimer::stop() {
  this->started = false;
  this->paused = false;
  this->startTicks = 0;
  this->pausedTicks = 0;
}

void hcTimer::pause() {
  if (this->started && !this->paused) {
    this->paused = true;

    this->pausedTicks = SDL_GetTicks() - this->startTicks;
    this->startTicks = 0;
  }
}

void hcTimer::unpause() {
  if (this->started && this->paused) {
    this->paused = false;
    this->startTicks = SDL_GetTicks() - this->pausedTicks;
    this->pausedTicks = 0;
  }
}

bool hcTimer::isStarted() { return this->started; }

bool hcTimer::isPaused() { return this->paused && this->started; }

uint32_t hcTimer::getTicks() {
  uint32_t time = 0;
  if (this->started) {
    if (this->paused) {
      time = this->pausedTicks;
    } else {
      time = SDL_GetTicks() - startTicks;
    }
  }
  return time;
}
