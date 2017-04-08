#pragma once

#include <memory>
#include "../base/macros.h"

using std::unique_ptr;

NS_HC_BEGIN

class Point {
public:
  Point() = default;
  int x;
  int y;
  Point(int x, int y) : x(x), y(y){};
};

using PointUPtr = unique_ptr<Point>;

NS_HC_END
