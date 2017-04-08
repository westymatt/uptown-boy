#pragma once
#include "macros.h"
#include <cstdint>

NS_HC_BEGIN

class Timer {
public:
  Timer() : startTicks_(0), pausedTicks_(0), paused_(false), started_(false){};

  void start();
  void stop();
  void pause();
  void unpause();

  uint32_t getTicks();

  bool isStarted();
  bool isPaused();

private:
  uint32_t startTicks_;
  uint32_t pausedTicks_;

  bool paused_;
  bool started_;
};

NS_HC_END
