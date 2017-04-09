#pragma once

#include "../base/macros.h"
#include <SDL2/SDL.h>

NS_HC_BEGIN

class Camera {
  SDL_Rect bounds_;

public:
  Camera();
};

NS_HC_END