#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

#include <cmath>

struct point_t {
  double x, y;
};

struct rectangle_t {
  double width, height;
  point_t pos;
};

static double getLength(const point_t &p1, const point_t &p2){
  double dx = p2.x - p1.x;
  double dy = p2.y - p1.y;
  return sqrt(dx * dx + dy * dy);
};

#endif
