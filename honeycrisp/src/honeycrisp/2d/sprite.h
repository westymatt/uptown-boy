#pragma once

#include "../base/gameobject.h"
#include "../base/macros.h"
#include "../base/sdl.h"
#include "../renderer/drawable.h"
#include "../renderer/texture.h"
#include "geometry/rect.h"
#include "node.h"
#include "vector.h"
#include <SDL2/SDL.h>
#include <memory>
#include <string>

using std::shared_ptr;
using std::make_unique;
using std::make_shared;

NS_HC_BEGIN

class Sprite : public Node {
public:
  std::unique_ptr<Texture> texture;
  Rect srcRect;
  Rect dstRect;
  Sprite(Rect srcRect, Rect dstRect) : srcRect(srcRect), dstRect(dstRect){};
  ~Sprite();
  void loadTexture(std::string filepath, RendererSPtr renderer);
  void render();

  void setAnchorPoint(Point &&pt);
  void setPosition(Point &&pt);
  void setScale(float x, float y);
  void setScale(Vector2f factors);

private:
  Vector2f scale_;
};

using SpriteUPtr = unique_ptr<Sprite>;
using SpriteSPtr = shared_ptr<Sprite>;

NS_HC_END
