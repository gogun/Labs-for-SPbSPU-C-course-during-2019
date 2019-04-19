#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <stdexcept>

che::Circle::Circle(const point_t & center, double radius) :
  center_(center),
  radius_(radius)
{
  if (radius_ < 0)
  {
    throw std::invalid_argument("Radius can not be negative");
  }

}

void che::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void che::Circle::move(const point_t & point)
{
  center_ = point;
}

void che::Circle::scale(double coef)
{
  if (coef <= 0)
  {
    throw std::invalid_argument("Not a positive parameter");
  }
  radius_ *= coef;
}

double che::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

che::rectangle_t che::Circle::getFrameRect() const
{
  return { radius_ * 2, radius_ * 2, center_ };
}

