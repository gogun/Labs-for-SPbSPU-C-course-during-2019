#include "circle.hpp"
#include <cassert>
#include <cmath>

Circle::Circle(const point_t &position, double radius) :
  center_(position),
  radius_(radius)
{
  assert(radius_ >= 0.0);
}

double Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

rectangle_t Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, center_};
}

void Circle::move(double dx, double dy)
{
  center_.x = dx;
  center_.y = dy;
}

void Circle::move(const point_t &position)
{
  center_ = position;
}
