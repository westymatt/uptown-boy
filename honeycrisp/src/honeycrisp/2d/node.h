#pragma once

#include "../base/macros.h"
#include "../base/sdl.h"

NS_HC_BEGIN

class Node {
private:
  RendererSPtr renderer_;

public:
  virtual void render() = 0;
  void setRenderer(RendererSPtr renderer) { this->renderer_ = renderer; }
  int localZOrder;
};

NS_HC_END
