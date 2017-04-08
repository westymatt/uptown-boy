#pragma once

#include <iostream>
#include <string>
#include <map>
#include <cstddef>
#include <SDL2/SDL.h>
#include "../base/macros.h"

NS_HC_BEGIN

class TextureManager {
public:
  static TextureManager *instance() {
    if (s_pInstance == nullptr) {
      s_pInstance = new TextureManager();
    }
    return s_pInstance;
  }

  bool load(std::string fileName, std::string id, SDL_Renderer *pRenderer);

  void clearTextureMap();
  void clearFromTextureMap(std::string id);

  void draw(std::string id, int x, int y, int width, int height,
            SDL_Renderer *pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
  void drawFrame(std::string id, int x, int y, int width, int height,
                 int currentRow, int currentFrame, SDL_Renderer *pRenderer,
                 double angle, int alpha,
                 SDL_RendererFlip flip = SDL_FLIP_NONE);
  void drawTile(std::string id, int margin, int spacing, int x, int y,
                int width, int height, int currentRow, int currentFrame,
                SDL_Renderer *pRenderer);

  std::map<std::string, SDL_Texture *> getTextureMap() { return m_textureMap; }

private:
  TextureManager(){};
  ~TextureManager(){};

  TextureManager(const TextureManager &);
  TextureManager &operator=(const TextureManager &);

  std::map<std::string, SDL_Texture *> m_textureMap;

  static TextureManager *s_pInstance;
};

typedef TextureManager TheTextureManager;

NS_HC_END
