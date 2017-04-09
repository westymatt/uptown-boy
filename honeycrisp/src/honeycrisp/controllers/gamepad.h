#pragma once
#include "../base/macros.h"
#include <SDL2/SDL.h>

NS_HC_BEGIN

namespace Controllers {

class Gamepad {
public:
  Gamepad(){};
  virtual void update() = 0;
};

} // namespace Controllers

NS_HC_END
