#include "circle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

Circle::Circle(const point_t &newCenter, double radius) :
  center_(newCenter),
  radius_(radius)
{
  assert(radius_ > 0);
}

void Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::move(const point_t &newCenter)
{
  center_ = newCenter;
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}
