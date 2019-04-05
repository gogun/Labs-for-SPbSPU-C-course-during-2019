#include "circle.hpp"
#include <math.h>
#include <iostream>
#include <cassert>

Circle::Circle (double radius, point_t pos):
  radius_(radius),
  pos_(pos)
{
  assert(radius > 0.0);
}

void Circle::displayData() const
{
  std::cout << "\nRadius: " << radius_
    << "\nPosition: (" << pos_.x << ';' << pos_.y << ')';
}

double Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return rectangle_t{radius_ * 2, radius_ * 2, {pos_.x, pos_.y}};
}

void Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Circle::move(point_t dot)
{
  pos_ = dot;
}
