#include "texture.h"
#include <SDL2/SDL_image.h>
#include "../utils/logging.h"

USING_NS_HC;

Texture::~Texture() {}

void Texture::loadTexture() {
  this->texture_ = IMG_LoadTexture(&*this->renderer_, this->filepath_.c_str());
  if (this->texture_ == nullptr) {
    LOG(IMG_GetError());
  }
}

void Texture::render() {
  const SDL_Rect *src = NULL;
  const SDL_Rect *dst = NULL;
  src = this->srcRect_.getRect();
  dst = this->dstRect_.getRect();
  SDL_RenderCopy(&*this->renderer_, this->texture_, src, dst);
}

void Texture::setScale(Vector2f factors) { this->scale_ = factors; }
