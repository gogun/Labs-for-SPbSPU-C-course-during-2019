#include "circle.hpp"
#include <cmath>
#include <stdexcept>

Circle::Circle(double radius, const point_t &center) :
  radius_(radius),
  center_(center)
{
  if (radius_ < 0.0)
  {
    throw std::invalid_argument("Invalid radius");
  }
}

double Circle::getArea() const noexcept
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const noexcept
{
  return {2 * radius_, 2 * radius_, center_};
}

void Circle::move(double dx, double dy) noexcept
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::move(const point_t &newPos) noexcept
{
  center_ = newPos;
}
