#pragma once

#define HONEYCRISP_VERSION = 0.1

#include "base/config.h"
#include "base/game.h"
#include "base/gameobject.h"
#include "base/macros.h"
#include "base/sdl.h"
#include "base/singleton.h"
#include "base/thread.h"
#include "base/thread.h"
#include "base/timer.h"

// Renderer
#include "renderer/drawable.h"
#include "renderer/loaderparams.h"
#include "renderer/texture.h"
#include "renderer/texturemanager.h"

// 2d
#include "2d/actions/action.h"
#include "2d/actions/moveby.h"
#include "2d/actions/sequence.h"
#include "2d/geometry/rect.h"
#include "2d/node.h"
#include "2d/point.h"
#include "2d/scene.h"
#include "2d/surface.h"
#include "2d/vector.h"

// Sprites
#include "2d/sprite.h"
#include "2d/spritesheet.h"

// Utils
#include "utils/logging.h"
#include "utils/utils.h"

// Controllers
#include "controllers/controller.h"
#include "controllers/keyboard.h"
#include "controllers/gamepad.h"

// Entity System
#include "entities/entity.h"
