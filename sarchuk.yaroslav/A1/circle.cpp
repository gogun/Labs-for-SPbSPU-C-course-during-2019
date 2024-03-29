#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

Circle::Circle(const point_t &position, double radius) :
  pos_(position),
  radius_(radius)
{
  assert(radius > 0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

void Circle::writeInfo() const
{
  std::cout << "Circle info:\n"
    << "Radius - " << radius_ << "\n"
    << "Center position - x = " << pos_.x << ", y = " << pos_.y << "\n"
    << "Area - " << getArea() << "\n\n";
}

void Circle::move(const point_t &pos)
{
  pos_ = pos;
}

void Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

rectangle_t Circle::getFrameRect() const
{
  return {pos_, 2 * radius_, 2 * radius_};
}
