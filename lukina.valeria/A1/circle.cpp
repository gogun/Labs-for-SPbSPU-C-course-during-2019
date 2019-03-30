#include <iostream>
#include <cmath>
#include <cassert>
#include "circle.hpp"

Circle::Circle(double r, point_t c):
  radius_(r),
  center_(c)
{
  assert (radius_ > 0);
}

double Circle::getArea() const
{
  return M_PI*radius_*radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {radius_*2, radius_*2, center_ };
}

void Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::move(point_t NewPoint)
{
  center_ = NewPoint;
}
