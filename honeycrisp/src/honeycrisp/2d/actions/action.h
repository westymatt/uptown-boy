#pragma once

#include "../../base/macros.h"

NS_HC_BEGIN

class Action {
public:
  Action() = default;
  virtual bool isDone() = 0;
  virtual void start() = 0;
  virtual void stop() = 0;
  virtual void step() = 0;
  virtual void update() = 0;
};

NS_HC_END
