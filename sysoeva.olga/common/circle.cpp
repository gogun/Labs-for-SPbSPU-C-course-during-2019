#define _USE_MATH_DEFINES
#include "circle.hpp"

#include <cassert>
#include <cmath>
#include <iostream>
#include <stdexcept>

sysoeva::Circle::Circle(double radius, const point_t &center):
  radius_(radius),
  center_(center)
{
  if (radius_ <= 0.0)
  {
    throw std::invalid_argument("Radius has invalid value");
  }
}

double sysoeva::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

sysoeva::rectangle_t sysoeva::Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, center_};
}

void sysoeva::Circle::move(const point_t &center)
{
  center_ = center;
}

void sysoeva::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void sysoeva::Circle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Coefficient has invalid value");
  }
  radius_ *= coefficient;
}
