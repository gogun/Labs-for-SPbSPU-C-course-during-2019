#include "circle.hpp"
#include <cassert>

const double pi =3.14159265359;

Circle::Circle(const double radius, const point_t &center) :
  radius_(radius),
  center_(center)
{
  assert(radius >= 0.0);
}

double Circle::getArea() const
{
  return pi * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2 ,center_};
}

void Circle::move(const double dx, const double dy)
{
  center_.x = dx;
  center_.y = dy;
}

void Circle::move(const point_t & newPos)
{
  center_ = newPos;
}
