#pragma once

#include "SDL2/SDL_thread.h"
#include "macros.h"

NS_HC_BEGIN

typedef void (*callback_t)(void *);

class Thread {
public:
  Thread() = default;
  Thread(callback_t callback) : callback_(callback){};
  void execute();

private:
  SDL_Thread *thread_;
  callback_t callback_;
  int threadReturnValue_;
};

NS_HC_END
