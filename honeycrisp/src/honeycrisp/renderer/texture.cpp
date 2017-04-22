#include "texture.h"
#include "../utils/logging.h"
#include <SDL2/SDL_image.h>

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
  SDL_Rect *dst = NULL;
  src = this->srcRect_.getRect();
  dst = this->dstRect_.getRect();
  dst->w *= this->scale_.x;
  dst->h *= this->scale_.y;
  SDL_RenderCopy(&*this->renderer_, this->texture_, src, dst);
}

void Texture::setScale(Vector2f factors) { this->scale_ = factors; }
