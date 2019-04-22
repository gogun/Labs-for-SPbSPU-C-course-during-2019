#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

korshunov::Circle::Circle(const point_t &center, double radius):
  center_(center),
  radius_(radius)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Invalid radius");
  }
}

double korshunov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

korshunov::rectangle_t korshunov::Circle::getFrameRect() const
{
  return rectangle_t
  {
    center_,
    2 * radius_,
    2 * radius_
  };
}

void korshunov::Circle::move(const point_t &center)
{
  center_ = center;
}

void korshunov::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void korshunov::Circle::scale(double scale)
{
  if (scale <= 0.0)
  {
    throw std::invalid_argument("Invalid scale");
  }
  radius_ *= scale;
}
