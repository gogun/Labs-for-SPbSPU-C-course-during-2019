#include "circle.hpp"

#include <math.h>
#include <iostream>

chizhov::Circle::Circle(point_t position, double radius) :
    center_(position),
    radius_(radius)
{
  if (radius_ <= 0) {
    throw std::invalid_argument("Radius must be positive");
  }
}

chizhov::Circle::Circle(double x, double y, double radius) :
    Circle(point_t{x, y}, radius)
{ }

double chizhov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

chizhov::rectangle_t chizhov::Circle::getFrameRect() const
{
  return rectangle_t{radius_ * 2, radius_ * 2, center_};
}

void chizhov::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void chizhov::Circle::move(point_t position)
{
  center_ = position;
}

void chizhov::Circle::scale(double scale)
{
  if (scale <= 0) {
    throw std::invalid_argument("You cannot scale by non-positive multiplier");
  }

  radius_ *= scale;
}
