#pragma once

#include "../renderer/loaderparams.h"
#include "macros.h"

NS_HC_BEGIN

class GameObject {
public:
  GameObject(){};
  ~GameObject(){};
  virtual void draw() = 0;
  virtual void update() = 0;
  virtual void clean() = 0;

protected:
  GameObject(const LoaderParams *pParams){};
};

NS_HC_END
