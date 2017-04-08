#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include <string>
#include "../base/gameobject.h"
#include "../utils/logging.h"
#include "../base/macros.h"

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
