#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <cassert>

Circle::Circle(const point_t& pos, double radius):
  pos_{pos},
  radius_{radius}
{
  assert(radius > 0);
}

double Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return {pos_, 2 * radius_, 2 * radius_};
}

point_t Circle::getCenter() const
{
  return pos_;
}

void Circle::move(const point_t& point)
{
  pos_ = point;
}

void Circle::move(double x, double y)
{
  pos_.x += x;
  pos_.y += y;
}
