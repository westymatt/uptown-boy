#include "sprite.h"
#include <utility>

USING_NS_HC;

Sprite::~Sprite() {}

void Sprite::loadTexture(std::string filepath, RendererSPtr renderer) {
  this->texture = std::make_unique<Texture>(filepath, renderer, this->srcRect,
                                            this->dstRect);
  this->texture->loadTexture();
}

void Sprite::render() { this->texture->render(); }

void Sprite::setAnchorPoint(Point &&pt) { /* todo */
}

void Sprite::setPosition(Point &&pt) { this->dstRect.point = pt; }

void Sprite::setScale(float x, float y) {
  Vector2f vec(x, y);
  this->texture->setScale(vec);
}

void Sprite::setScale(Vector2f factors) { this->texture->setScale(factors); }
