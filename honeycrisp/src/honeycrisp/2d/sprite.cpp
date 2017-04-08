#include "sprite.h"
#include <utility>

USING_NS_HC;

Sprite::~Sprite() {}

void Sprite::loadTexture(std::string filepath, RendererSPtr renderer) {
  this->texture = std::make_unique<Texture>(filepath, renderer, this->srcRect_,
                                            this->dstRect_);
  this->texture->loadTexture();
}

void Sprite::render() { this->texture->render(); }

void Sprite::setAnchorPoint(Point &&pt) { /* todo */
}

void Sprite::setPosition(Point &&pt) { this->dstRect_.point = pt; }

void Sprite::setScale(float x, float y) {}

void Sprite::setScale(Vector2f factors) {
  this->texture->setScale(factors);
}
