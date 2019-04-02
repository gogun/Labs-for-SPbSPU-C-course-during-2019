#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

Circle::Circle(point_t pos, double r):
  center_(pos),
  radius_(r)
{
  assert(r > 0);
}

Circle::Circle(double x, double y, double r):
  Circle({x, y}, r)
{
  assert(r > 0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {center_, 2 * radius_, 2 * radius_};
}

void Circle::move(point_t point)
{
  center_ = point;
}

void Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}
