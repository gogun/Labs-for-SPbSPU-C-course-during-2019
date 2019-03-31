#include "circle.hpp"
#include <cmath>
#include <cassert>

Circle::Circle(point_t point, double rad):
center_(point),
radius_(rad)
{
  assert(radius_>=0.0);
}

Circle::Circle(double x, double y, double rad):
  Circle::Circle({x,y},rad)
{}

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
