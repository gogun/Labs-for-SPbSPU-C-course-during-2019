#include "circle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

utin::Circle::Circle(const utin::point_t &center, const double &radius):
  center_(center),
  radius_(radius)
{
  assert(radius_ > 0.0);
}

double utin::Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

utin::rectangle_t utin::Circle::getFrameRect() const
{
  return {center_, radius_ * 2, radius_ * 2};
}

void utin::Circle::move(const double &dx, const double &dy)
{
  center_.x += dx;
  center_.y += dy;
}

void utin::Circle::move(const point_t &point)
{
  center_ = point;
}

void utin::Circle::scale(const double &multiplier)
{
  radius_ *= multiplier;
}

void utin::Circle::printInfo() const
{
  std::cout << "Radius of circle is " << radius_ << '\n'
            << "Center of circle is (" << center_.x << ";" << center_.y << ")" << '\n';
}
