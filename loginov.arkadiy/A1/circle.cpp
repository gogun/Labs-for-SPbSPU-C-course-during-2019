#include "circle.hpp"
#include <cassert>
#include <cmath>

Circle::Circle(const point_t &point, double radius):
  centre_(point),
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
  return { 2 * radius_, 2 * radius_, centre_ };
}

void Circle::move(double dx, double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}

void Circle::move(const point_t &point)
{
  centre_ = point;
}

point_t Circle::getCentre() const
{
  return getFrameRect().pos;
}
