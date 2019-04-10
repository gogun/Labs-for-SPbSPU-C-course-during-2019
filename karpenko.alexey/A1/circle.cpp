#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <cassert>


Circle::Circle(const double radius, const point_t & center) :
  center_(center),
  radius_(radius)
{
  assert(radius > 0.0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return { radius_ * 2, radius_ * 2 ,center_ };
}

void Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::move(const point_t & newPos)
{
  center_ = newPos;
}
