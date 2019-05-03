#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

potapova::Circle::Circle(const point_t &center, double radius) :
  center_(center),
  radius_(radius)
{
  if (radius_ < 0)
  {
    throw std::invalid_argument("Invalid radius");
  }
}

double potapova::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

void potapova::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void potapova::Circle::move(const point_t &center)
{
  center_ = center;
}

potapova::rectangle_t potapova::Circle::getFrameRect() const
{
  return rectangle_t{center_, radius_ * 2, radius_ * 2};
}

void potapova::Circle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Invalid coefficient");
  }
  radius_ *= coefficient;
}
