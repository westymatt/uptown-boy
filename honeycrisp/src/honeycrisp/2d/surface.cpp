#include "surface.h"

USING_NS_HC;

Surface::Surface(std::string filepath, SDL_PixelFormat *screenFormat) {
  SDL_Surface *surface = IMG_Load(filepath.c_str());
  if (surface == NULL) {
    LOG(IMG_GetError());
  } else {
    this->surface_ = SDL_ConvertSurface(surface, screenFormat, 0);
    if (this->surface_ == NULL) {
      LOG(IMG_GetError());
    }
  }
}

Surface::~Surface(){};

void Surface::render() {}
