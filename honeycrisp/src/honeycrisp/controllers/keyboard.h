#pragma once
#include "../base/macros.h"
#include "controller.h"
#include <iostream>
#include <map>
using std::map;

NS_HC_BEGIN

namespace Controllers {
using KeyboardState = const Uint8 *;

class Keyboard {
private:
  KeyboardState currentState;

  KeyboardState getState() { return SDL_GetKeyboardState(NULL); }

public:
  void update() { currentState = getState(); }

  bool isPressed(int keycode) {
    if (currentState != nullptr && currentState != NULL) {
      return static_cast<bool>(currentState[keycode]);
    }
    return false;
  }
};
} // namespace Controllers

NS_HC_END
