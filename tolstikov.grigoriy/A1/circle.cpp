#include "circle.hpp"
#include <iostream>
#include <cassert>
#include <math.h>

Circle::Circle(point_t centre, double radius):
  centre_(centre),
  radius_(radius)
{
  assert(radius > 0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {centre_, 2 * radius_, 2 * radius_};
}

void Circle::move(point_t point)
{
  centre_ = point;
}

void Circle::move(double dx, double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}
