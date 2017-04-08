#pragma once
#include "controller.h"
#include "../base/macros.h"
#include "../base/singleton.h"
#include <map>

using std::map;

NS_HC_BEGIN

namespace Keyboard {
  using KeyboardState = const Uint8 *;

  extern KeyboardState currentState;

  extern KeyboardState getState() {
    return SDL_GetKeyboardState(NULL);
  }

  extern void update() {
    currentState = getState();
  }

  extern bool isPressed(int keycode) {
    if (currentState != nullptr && currentState != NULL) {
      return static_cast<bool>(currentState[keycode]);
    }
    return false;
  }
}

NS_HC_END
