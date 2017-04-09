#pragma once

#include "../base/macros.h"
#include "sprite.h"
#include <memory>
#include <utility>

using std::unique_ptr;
using std::move;

NS_HC_BEGIN

class Spritesheet {
public:
  Spritesheet(SpriteUPtr sprite) { this->sprite = move(sprite); };
  SpriteUPtr sprite;
};

using SpritesheetUPtr = unique_ptr<Spritesheet>;
using SpritesheetSPtr = shared_ptr<Spritesheet>;

NS_HC_END
