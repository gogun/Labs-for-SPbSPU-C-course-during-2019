#include "circle.hpp"
#include <cmath>
#include <stdexcept>

besedin::Circle::Circle(const double radius, const point_t &center) :
  radius_(radius),
  center_(center)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Wrong circle radius");
  }
}

double besedin::Circle::getArea() const noexcept
{
  return M_PI * radius_ * radius_;
}

besedin::rectangle_t besedin::Circle::getFrameRect() const noexcept
{
  return {2 * radius_, 2 * radius_, center_};
}

void besedin::Circle::move(const double dx, const double dy) noexcept
{
  center_.x += dx;
  center_.y += dy;
}

void besedin::Circle::move(const point_t &newPos) noexcept
{
  center_ = newPos;
}

void besedin::Circle::scale(const double scale)
{
  if (scale <= 0.0)
  {
    throw std::invalid_argument("Wrong scaling factor");
  }
  else
  {
    radius_ *= scale;
  }
}
