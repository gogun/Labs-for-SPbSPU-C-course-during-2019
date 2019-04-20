#include "circle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

Circle::Circle(const point_t &center, const double &radius):
  center_(center),
  radius_(radius)
{
  assert(radius_ > 0.0);
}

double Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

rectangle_t Circle::getFrameRect() const
{
  return {center_, radius_ * 2, radius_ * 2};
}

void Circle::move(const double &dx, const double &dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::move(const point_t &point)
{
  center_ = point;
}

void Circle::printInfo() const
{
  std::cout << "Radius of circle is " << radius_ << '\n'
            << "Center of circle is (" << center_.x << ";" << center_.y << ")" << '\n';
}
