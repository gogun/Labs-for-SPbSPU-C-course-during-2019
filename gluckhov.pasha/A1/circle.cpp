#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <cassert>
#include <math.h>
#include <iostream>

Circle::Circle (double radius, const point_t &position):
  pos_(position),
  radius_(radius)
{
  assert(radius > 0.0);
}

double Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, pos_};
}

void Circle::printData() const
{
  std::cout << "Radius: " << radius_;
  std::cout << "\nPosition: (" << pos_.x << ';' << pos_.y << ')';
}

void Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Circle::move(const point_t &newPos)
{
  pos_ = newPos;
}
