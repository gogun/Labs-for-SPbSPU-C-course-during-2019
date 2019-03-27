#include "circle.hpp"
#include <cmath>
#include <cassert>

Circle::Circle(point_t dot, double rad):
center_(dot),
radius_(rad)
{
  assert(radius_>=0.0);
}

double Circle::getArea() const {
  return M_PI*radius_*radius_;
}

rectangle_t Circle::getFrameRect() const {
  return {radius_*2,radius_*2,center_};
}

void Circle::move(double dx, double dy) {
  center_.x+=dx;
  center_.y+=dy;
}

void Circle::move(point_t point) {
  center_=point;
}