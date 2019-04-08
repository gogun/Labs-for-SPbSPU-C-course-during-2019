#include "circle.hpp"
#include <cmath>
#include <cassert>

Circle::Circle(const double radius, const point_t &center) :
  radius_(radius),
  center_(center)
{
  assert(radius_ > 0.0);
}

double Circle::getArea() const noexcept
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const noexcept
{
  return {2 * radius_, 2 * radius_, center_};
}

void Circle::move(const double dx, const double dy) noexcept
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::move(const point_t &newPos) noexcept
{
  center_ = newPos;
}
