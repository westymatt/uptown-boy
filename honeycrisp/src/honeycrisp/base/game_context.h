#pragma once

#include "../controllers/keyboard.h"
#include "../controllers/gamepad.h"
#include "sdl.h"
#include "macros.h"
#include <vector>

NS_HC_BEGIN

using std::vector;

namespace Base {
struct hcGameContext_t {
  vector<Controllers::Gamepad *> gamepads;
  Controllers::Keyboard *keyboard;
  RendererSPtr renderer;  
};

using hcGameContext = hcGameContext_t;
} // namespace Base

NS_HC_END