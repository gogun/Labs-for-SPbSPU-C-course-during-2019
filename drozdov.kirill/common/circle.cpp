#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <math.h>
#include <iostream>
#include <cassert>

drozdov::Circle::Circle (double radius, const point_t &pos):
  radius_(radius),
  pos_(pos)
{
  assert(radius > 0.0);
}

void drozdov::Circle::printData() const
{
  std::cout << "\nRadius: " << radius_ << "\nPosition: (" << pos_.x << ';' << pos_.y << ')' << std::endl;
}

double drozdov::Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

rectangle_t drozdov::Circle::getFrameRect() const
{
  return rectangle_t{radius_ * 2, radius_ * 2, pos_};
}

void drozdov::Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void drozdov::Circle::move(const point_t &dot)
{
  pos_ = dot;
}
