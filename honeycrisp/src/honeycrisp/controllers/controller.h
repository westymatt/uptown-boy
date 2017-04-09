#pragma once
#include "../base/macros.h"
#include <SDL2/SDL.h>

NS_HC_BEGIN

class Controller {
public:
  Controller(){};
  virtual void update() = 0;
};

NS_HC_END
