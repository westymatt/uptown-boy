#pragma once

#include <memory>
#include "../utils/logging.h"
#include "../base/macros.h"

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
