#pragma once

#include <SDL2/SDL.h>
#include "../base/macros.h"

NS_HC_BEGIN

class Camera {
  SDL_Rect bounds_;
public:
  Camera();
};

NS_HC_END