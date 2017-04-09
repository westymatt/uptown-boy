#pragma once

#include "../../base/macros.h"
#include "../point.h"
#include <SDL2/SDL.h>
#include <memory>
#include <utility>

using std::make_unique;

NS_HC_BEGIN

class Rect {
public:
  Rect(int x, int y, int width, int height) : width(width), height(height) {
    this->point.x = x;
    this->point.y = y;
  };
  Point point;
  int width;
  int height;

  const SDL_Rect *getRect() {
    this->rect_.x = this->point.x;
    this->rect_.y = this->point.y;
    this->rect_.w = this->width;
    this->rect_.h = this->height;
    return static_cast<SDL_Rect *>(&this->rect_);
  };

  void setPoint(Point &&pt) { this->point = pt; }

  void setX(int x) { this->point.x = x; };
  void incX(int x) { this->point.x += x; };
  void decX(int x) { this->point.x -= x; };

  void setY(int y) { this->point.y = y; };
  void incY(int y) { this->point.y += y; };
  void decY(int y) { this->point.y -= y; };

  int getX() { return this->point.x; };
  int getY() { return this->point.y; };

private:
  SDL_Rect rect_;
};

NS_HC_END
