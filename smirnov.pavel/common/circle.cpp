#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

smirnov::Circle::Circle(double radius, const point_t & center):
  radius_(radius),
  center_(center)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Radius must be positive. ");
  }
}

double smirnov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

smirnov::rectangle_t smirnov::Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, center_};
}

void smirnov::Circle::move(const point_t & new_point)
{
  center_ = new_point;
}

void smirnov::Circle::move(double x_delta, double y_delta)
{
  center_.x += x_delta;
  center_.y += y_delta;
}

void smirnov::Circle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Coefficient must be positive. ");
  }
  radius_ *= coefficient;
}

void smirnov::Circle::getInfo() const
{
  std::cout << "Area of circle is " << getArea() << "\n";
  std::cout << "Radius of circle is " << radius_ << "\n";
  std::cout << "Center of circle is (" << center_.x << ";" << center_.y << ")\n";
}
