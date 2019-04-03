#include "circle.hpp"
#include <cassert>

const double Pi = 3.1415926535;

Circle::Circle(point_t position, double radius):
  position_(position),
  radius_(radius)
{
  assert(radius > 0);
}

double Circle::getArea() const
{
  return Pi * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {position_, radius_ * 2, radius_ * 2};
}

void Circle::move(point_t newPosition)
{
  position_ = newPosition;
}

void Circle::move(double dx, double dy)
{
  position_.x += dx;
  position_.y += dy;
}
