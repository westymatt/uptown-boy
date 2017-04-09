#pragma once

#include "../base/macros.h"
#include "../utils/logging.h"
#include <memory>

using std::unique_ptr;
using std::shared_ptr;

NS_HC_BEGIN

struct GameConfig {
  const char *title;
  int fps;
  int xpos;
  int ypos;
  int width;
  int height;
  int flags;
};

using GameConfigUPtr = unique_ptr<GameConfig>;
using GameConfigSPtr = shared_ptr<GameConfig>;

NS_HC_END
