#pragma once

#include "../base/macros.h"

NS_HC_BEGIN

class RenderTarget;

class Drawable {
public:
  virtual ~Drawable() {}

protected:
  friend class RenderTarget;
  virtual void draw(RenderTarget &target) const = 0;
};

NS_HC_END
