#pragma once

#include "../2d/scene.h"
#include "../2d/sprite.h"
#include "../base/config.h"
#include "../base/macros.h"
#include "../base/sdl.h"
#include "../utils/logging.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL2_framerate.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

NS_HC_BEGIN

using std::unique_ptr;
using std::map;
using std::string;
using std::vector;

namespace Base {
struct hcGameContext_t {};

using hcGameContext = hcGameContext_t;
} // namespace Base

NS_HC_END