#include "circle.hpp"
#include <cmath>
#include <cassert>

Circle::Circle(const point_t &centre, double radius):
  centre_(centre),
  radius_(radius)
{
  assert(radius_ > 0.0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, centre_};
}

void Circle::move(const point_t &point)
{
  centre_ = point;
}

void Circle::move(double dx, double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}
