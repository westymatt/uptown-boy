#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include <string>
#include "macros.h"
#include "../utils/logging.h"

using std::unique_ptr;
using std::shared_ptr;
using std::default_delete;
using std::string;

NS_HC_BEGIN

/*
 * Base Pointer Types
 */
template <typename T, typename D = default_delete<T>>
using sdl_u_ptr = unique_ptr<T, D>;

template <typename T, typename D = default_delete<T>>
using sdl_s_ptr = shared_ptr<T>;

/*
 * SDL Universal Deleter
 */
struct sdl_deleter {
  void operator()(SDL_Window *p) const {
    if (p) {
      SDL_DestroyWindow(p);
    }
  }
  void operator()(SDL_Renderer *p) const {
    if (p) {
      SDL_DestroyRenderer(p);
    }
  }
  void operator()(SDL_Texture *p) const {
    if (p) {
      SDL_DestroyTexture(p);
    }
  }
  void operator()(SDL_Surface *p) const {
    if (p) {
      SDL_FreeSurface(p);
    }
  }
  void operator()(SDL_Joystick *p) const {
    if (p) {
      SDL_JoystickClose(p);
      p = nullptr;
    }
  }
};

/*
 * Pointer Types
 */
using WindowUPtr = sdl_u_ptr<SDL_Window, sdl_deleter>;
using RendererUPtr = sdl_u_ptr<SDL_Renderer, sdl_deleter>;
using TextureUPtr = sdl_u_ptr<SDL_Texture, sdl_deleter>;
using SurfaceUPtr = sdl_u_ptr<SDL_Surface, sdl_deleter>;
using JoystickUPtr = sdl_u_ptr<SDL_Joystick, sdl_deleter>;

using WindowSPtr = sdl_s_ptr<SDL_Window, sdl_deleter>;
using RendererSPtr = sdl_s_ptr<SDL_Renderer, sdl_deleter>;
using TextureSPtr = sdl_s_ptr<SDL_Texture, sdl_deleter>;
using SurfaceSPtr = sdl_s_ptr<SDL_Surface, sdl_deleter>;
using JoystickSPtr = sdl_s_ptr<SDL_Joystick, sdl_deleter>;
/*
 * Unique Ptr Factories
 */
inline auto make_sdl_u_ptr(SDL_Window *window)
    -> sdl_u_ptr<SDL_Window, sdl_deleter> {
  return sdl_u_ptr<SDL_Window, sdl_deleter>(window, sdl_deleter());
}

inline auto make_sdl_u_ptr(SDL_Renderer *renderer)
    -> sdl_u_ptr<SDL_Renderer, sdl_deleter> {
  return sdl_u_ptr<SDL_Renderer, sdl_deleter>(renderer, sdl_deleter());
}

inline auto make_sdl_u_ptr(SDL_Texture *texture)
    -> sdl_u_ptr<SDL_Texture, sdl_deleter> {
  return sdl_u_ptr<SDL_Texture, sdl_deleter>(texture, sdl_deleter());
}

inline auto make_sdl_u_ptr(SDL_Surface *surface)
    -> sdl_u_ptr<SDL_Surface, sdl_deleter> {
  return sdl_u_ptr<SDL_Surface, sdl_deleter>(surface, sdl_deleter());
}

/*
 * Shared Ptr Factories
 */
inline auto make_sdl_s_ptr(SDL_Window *window)
    -> sdl_s_ptr<SDL_Window, sdl_deleter> {
  return sdl_s_ptr<SDL_Window, sdl_deleter>(window, sdl_deleter());
}

inline auto make_sdl_s_ptr(SDL_Renderer *renderer)
    -> sdl_s_ptr<SDL_Renderer, sdl_deleter> {
  return sdl_s_ptr<SDL_Renderer, sdl_deleter>(renderer, sdl_deleter());
}

inline auto make_sdl_s_ptr(SDL_Texture *texture)
    -> sdl_s_ptr<SDL_Texture, sdl_deleter> {
  return sdl_s_ptr<SDL_Texture, sdl_deleter>(texture, sdl_deleter());
}

inline auto make_sdl_s_ptr(SDL_Surface *surface)
    -> sdl_s_ptr<SDL_Surface, sdl_deleter> {
  return sdl_s_ptr<SDL_Surface, sdl_deleter>(surface, sdl_deleter());
}

/*
 *  Unique Ptr Helpers
 */
inline auto make_unique_window(const char *title, int xpos, int ypos, int width,
                               int height, Uint32 flags) {
  return make_sdl_u_ptr(
      SDL_CreateWindow(title, xpos, ypos, width, height, flags));
}

inline auto make_unique_renderer(WindowUPtr &window, int x, Uint32 flags) {
  return make_sdl_u_ptr(SDL_CreateRenderer(&*window, x, flags));
}

inline auto make_unique_texture(RendererUPtr &renderer, string filepath) {
  return make_sdl_u_ptr(IMG_LoadTexture(&*renderer, filepath.c_str()));
}

inline auto make_unique_surface(string filepath,
                                SDL_PixelFormat *screenFormat) {
  return make_sdl_u_ptr(IMG_Load(filepath.c_str()));
}

/*
 * Shared Ptr Helpers
 */
inline auto make_shared_window(const char *title, int xpos, int ypos, int width,
                               int height, Uint32 flags) {
  return make_sdl_s_ptr(
      SDL_CreateWindow(title, xpos, ypos, width, height, flags));
}

inline auto make_shared_renderer(WindowSPtr &window, int x, Uint32 flags) {
  return make_sdl_s_ptr(SDL_CreateRenderer(&*window, x, flags));
}

inline auto make_shared_renderer(WindowUPtr &window, int x, Uint32 flags) {
  return make_sdl_s_ptr(SDL_CreateRenderer(&*window, x, flags));
}

inline auto make_shared_texture(RendererSPtr &renderer, string filepath) {
  return make_sdl_s_ptr(IMG_LoadTexture(&*renderer, filepath.c_str()));
}

inline auto make_shared_surface(string filepath,
                                SDL_PixelFormat *screenFormat) {
  return make_sdl_s_ptr(IMG_Load(filepath.c_str()));
}

NS_HC_END
