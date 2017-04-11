#pragma once
#include "../base/macros.h"
#include <SDL2/SDL.h>
#include "../base/sdl.h"
#include <memory>

NS_HC_BEGIN

namespace Controllers {

class Gamepad {
public:
  Gamepad(SDL_Joystick *joystick) :
    joystick(joystick) {};
private:
  SDL_Joystick *joystick;
};

} // namespace Controllers

NS_HC_END
