#include "circle.hpp"
#include <cassert>
#include <cmath>

Circle::Circle(const point_t &position, double radius):
  position_(position),
  radius_(radius)
{
  assert(radius > 0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {position_, radius_ * 2, radius_ * 2};
}

void Circle::move(const point_t &newPosition)
{
  position_ = newPosition;
}

void Circle::move(double dx, double dy)
{
  position_.x += dx;
  position_.y += dy;
}
