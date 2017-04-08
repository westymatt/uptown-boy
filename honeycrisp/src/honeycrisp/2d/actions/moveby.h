#pragma once

#include "action.h"
#include "../../base/macros.h"

NS_HC_BEGIN

class MoveBy : public Action {
public:
  MoveBy(int duration) : duration(duration){};
  virtual bool isDone() override { return false; }
  virtual void start() override{};
  virtual void stop() override{};
  virtual void step() override{};
  virtual void update() override{};

  int duration;
};

NS_HC_END
