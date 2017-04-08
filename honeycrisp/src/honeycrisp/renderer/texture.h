#pragma once

#include "../2d/geometry/rect.h"
#include "../2d/vector.h"
#include "../base/macros.h"
#include "../base/sdl.h"
#include <SDL2/SDL.h>
#include <memory>
#include <string>

using std::shared_ptr;

NS_HC_BEGIN

class Texture {
public:
  Texture(std::string filepath, RendererSPtr renderer, Rect &srcRect,
          Rect &dstRect)
      : filepath_(filepath), renderer_(renderer), srcRect_(srcRect),
        dstRect_(dstRect), scale_(Vector2f(1.0, 1.0)){};
  ~Texture();
  void loadTexture();
  void render();
  void setScale(Vector2f factors);

private:
  std::string filepath_;
  SDL_Texture *texture_;
  RendererSPtr renderer_;
  Rect &srcRect_;
  Rect &dstRect_;
  Vector2f scale_;
};

NS_HC_END
