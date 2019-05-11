#include "circle.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

moskovskaya::Circle::Circle(const point_t &newCenter, double radius) :
  center_(newCenter),
  radius_(radius)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Negative radius");
  }
}

void moskovskaya::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void moskovskaya::Circle::move(const point_t &newCenter)
{
  center_ = newCenter;
}

double moskovskaya::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

moskovskaya::rectangle_t moskovskaya::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void moskovskaya::Circle::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Negative factor");
  }
  radius_ *= factor;
}
