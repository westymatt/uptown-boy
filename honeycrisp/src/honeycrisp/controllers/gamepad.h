#pragma once
#include <SDL2/SDL.h>
#include "../base/macros.h"

NS_HC_BEGIN

namespace Controllers {

class Gamepad {
public:
  Gamepad(){};
  virtual void update() = 0;
};

}

NS_HC_END
