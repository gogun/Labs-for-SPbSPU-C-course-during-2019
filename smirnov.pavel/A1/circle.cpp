#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

Circle::Circle(double radius, const point_t & center) :
  radius_(radius),
  center_(center)
{
  assert(radius > 0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, center_};
}

void Circle::move(const point_t & new_point)
{
  center_ = new_point;
}

void Circle::move(double x_delta, double y_delta)
{
  center_.x += x_delta;
  center_.y += y_delta;
}

void Circle::getInfo() const
{
  std::cout << "Area of circle is "
      << getArea() << "\n";
  std::cout << "Radius of circle is "
      << radius_ << "\n";
  std::cout << "Center of circle is "
      << center_.x << ";" << center_.y << "\n";
}
