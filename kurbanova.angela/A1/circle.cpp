#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <cmath>
#include <cassert>
#include <iostream>

Circle::Circle(const point_t &center, double rad):
  pos_(center),
  radius_(rad)
{
  assert(rad > 0); 
}

double Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return {pos_, 2 * radius_, 2 * radius_};
}

void Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Circle::move(const point_t &pos1)
{
  pos_ = pos1;
}

void Circle::printInfo() const
{
  std::cout << "Area = " << getArea() << "\n"
            << "Radius = " << radius_ << "\n"
            << "Position (" << pos_.x << ", " << pos_.y << ")\n";
}
