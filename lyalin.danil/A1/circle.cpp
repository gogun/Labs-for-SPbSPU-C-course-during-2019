#include "circle.hpp"
#include <cassert>
#include <cmath>

Circle::Circle(point_t position, double radius) :
  center_(position),
  radius_(radius) {
  assert(radius_ >= 0.0);
}

Circle::Circle(double x, double y, double radius) :
  Circle({x, y}, radius) {
}

double Circle::getArea() const {
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const {
  return {radius_ * 2, radius_ * 2, center_};
}

void Circle::move(double dx, double dy) {
  center_.x = dx;
  center_.y = dy;
}

void Circle::move(point_t position) {
  center_ = position;
}
