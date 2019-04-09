#include "circle.hpp"
#include <cassert>
#include <cmath>

Circle::Circle(const point_t &center, const double &radius) :
  center_(center),
  radius_(radius)
{
  assert(radius_ >= 0.0);
}

rectangle_t Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

void Circle::move(const double &dx, const double &dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::move(const point_t &newPoint)
{
  center_ = newPoint;
}
