#include "circle.hpp"
#include <cassert>
#include <iostream>
#include <cmath>

Circle::Circle(const point_t &center, double radius):
  center_(center),
  radius_(radius)
{
  assert(radius_ > 0.0);
}

Circle::Circle(double x, double y, double radius):
  center_({x, y}),
  radius_(radius)
{
  assert(radius_ > 0.0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return rectangle_t{center_, radius_, radius_};
}

void Circle::move(const point_t &position)
{
  center_ = position;
}

void Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::printInf() const
{
  std::cout << "Parameters of circle: " << std::endl
    << "Center: (" << center_.x << ";" << center_.y << ")" << std::endl
    << "Radius: " << radius_ << std::endl
    << "Area: " << getArea() << std::endl;
}


