#pragma once

#include "../base/macros.h"
#include <SDL2/SDL.h>
#include <string>

NS_HC_BEGIN

using std::string;
using std::to_string;

#define LOG(message)                                                           \
  SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "%s",    \
                 message);

template <typename T> void log(T message) {
  string s = to_string(message);
  LOG(s.c_str());
}

NS_HC_END
