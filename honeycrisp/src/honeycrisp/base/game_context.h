#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_framerate.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <iostream>
#include <memory>
#include <map>
#include <string>
#include <vector>
#include "../utils/logging.h"
#include "../2d/sprite.h"
#include "../2d/scene.h"
#include "../base/config.h"
#include "../base/macros.h"
#include "../base/sdl.h"

NS_HC_BEGIN

using std::unique_ptr;
using std::map;
using std::string;
using std::vector;

namespace Base {
  struct hcGameContext_t {

  };

  using hcGameContext = hcGameContext_t;
} 

NS_HC_END