#include "circle.hpp"

#include <iostream>
#include <cmath>
#include <cassert>

Circle::Circle(const double radius, const point_t & pos) :
  radius_(radius),
  center_(pos)
{
assert (radius>0.0);
}

double Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return rectangle_t {2 * radius_, 2 * radius_, center_};
}

void Circle::move(const point_t & pos)
{
  center_.x += pos.x;
  center_.y += pos.y;
}

void Circle::move(double x, double y)
{
  center_.x += x;
  center_.y += y;
}