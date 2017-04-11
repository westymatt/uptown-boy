#pragma once
#include "macros.h"
#include <cstdint>

NS_HC_BEGIN

class hcTimer {
public:
  hcTimer();
  hcTimer(uint32_t startTicks, uint32_t pausedTicks, bool paused, bool started) :
    startTicks(startTicks), pausedTicks(pausedTicks), paused(paused), started(started) {}

  void start();
  void stop();
  void pause();
  void unpause();

  uint32_t getTicks();

  bool isStarted();
  bool isPaused();

private:
  uint32_t startTicks;
  uint32_t pausedTicks;

  bool paused;
  bool started;
};

NS_HC_END
