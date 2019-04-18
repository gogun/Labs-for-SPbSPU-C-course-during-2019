#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <math.h>
#include <iostream>
#include <cassert>

Circle::Circle (double radius, const point_t &pos):
  radius_(radius),
  pos_(pos)
{
  assert(radius > 0.0);
}

void Circle::printData() const
{
  std::cout << "\nRadius: " << radius_ << "\nPosition: (" << pos_.x << ';' << pos_.y << ')' << std::endl;
}

double Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return rectangle_t{radius_ * 2, radius_ * 2, pos_};
}

void Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Circle::move(const point_t &dot)
{
  pos_ = dot;
}
