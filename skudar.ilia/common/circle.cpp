#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

skudar::Circle::Circle(const point_t &position, double radius) :
  center_(position),
  radius_(radius)
{
  if (radius_ < 0.0)
  {
    throw std::invalid_argument("Radius must be a non-negative number");
  }
}

skudar::Circle::Circle(double x, double y, double radius) :
  Circle({x, y}, radius)
{
  if (radius_ < 0.0)
  {
    throw std::invalid_argument("Radius must be a non-negative number");
  }
}

double skudar::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

skudar::rectangle_t skudar::Circle::getFrameRect() const
{
  return {center_, 2 * radius_, 2 * radius_};
}

void skudar::Circle::move(point_t point)
{
  center_ = point;
}

void skudar::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void skudar::Circle::scale(double factor)
{
  if (factor <= 0.0)
  {
    throw std::invalid_argument("Circle scale factor must be a non-negative number");
  }
  else
  {
    radius_ *= factor;
  }
}
