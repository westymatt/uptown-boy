#pragma once
#include <SDL2/SDL.h>
#include "../base/macros.h"

NS_HC_BEGIN

class Controller {
public:
  Controller(){};
  virtual void update() = 0;
};

NS_HC_END
