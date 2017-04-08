#pragma once
#include "controller.h"
#include "../base/macros.h"
#include "../base/singleton.h"
#include <map>

using std::map;

NS_HC_BEGIN

namespace Keyboard {
  const Uint8 *currentState = nullptr;

  const Uint8* getState() {
    return SDL_GetKeyboardState(NULL);
  }

  void update() {
    currentState = getState();
  }

  bool isPressed(int keycode) {
    if (currentState != nullptr && currentState != NULL) {
      return static_cast<bool>(currentState[keycode]);
    }
    return false;
  }
}

NS_HC_END
