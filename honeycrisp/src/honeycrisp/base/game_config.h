#pragma once

#include "../base/macros.h"
#include "../utils/logging.h"
#include <memory>

using std::unique_ptr;
using std::shared_ptr;

NS_HC_BEGIN

struct hcGameConfig {
  const char *title;
  int fps;
  int xpos;
  int ypos;
  int width;
  int height;
  int flags;
};

using hcGameConfigUPtr = unique_ptr<hcGameConfig>;
using hcGameConfigSPtr = shared_ptr<hcGameConfig>;

NS_HC_END
