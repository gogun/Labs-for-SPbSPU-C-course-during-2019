#define _USE_MATH_DEFINES

#include "circle.hpp"
#include <cmath>
#include <cassert>

Circle::Circle(const double radius, const point_t &point):
  radius_(radius),
  pos_(point)
{
  assert(radius > 0);
}

double Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

rectangle_t Circle::getFrameRect() const
{
  return { radius_ * 2, radius_ * 2, pos_ };
}

void Circle::move(const point_t &point)
{
  pos_ = point;
}

void Circle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
