#pragma once

#include "../base/gameobject.h"
#include "../base/macros.h"
#include "../utils/logging.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include <string>

NS_HC_BEGIN

class Surface : GameObject {
public:
  Surface(std::string filepath, SDL_PixelFormat *screenFormat);
  ~Surface();
  void render();

private:
  SDL_Surface *surface_;
};

NS_HC_END
