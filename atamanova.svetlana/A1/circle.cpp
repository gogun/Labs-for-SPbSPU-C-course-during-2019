#include "circle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

Circle::Circle(point_t center, double radius) :
  center_(center),
  radius_(radius) {
  assert(radius_ > 0);
}

void Circle::move(double dx, double dy) {
  center_.x += dx;
  center_.y += dy;
}

void Circle::move(point_t point) {
  center_ = point;
}

double Circle::getArea() const {
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const {
  return {radius_ * 2, radius_ * 2, center_};
}
