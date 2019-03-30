#define _USE_MATH_DEFINES

#include "circle.hpp"
#include <cmath>
#include <cassert>

Circle::Circle(const point_t &centre, double radius):
  pos_(centre),
  radius_(radius)
{
  assert(radius_ > 0);
}

double Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

rectangle_t Circle::getFrameRect() const
{
  return rectangle_t{pos_, radius_ * 2, radius_ * 2};
}

void Circle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Circle::move(const point_t &point)
{
  pos_ = point;
}
