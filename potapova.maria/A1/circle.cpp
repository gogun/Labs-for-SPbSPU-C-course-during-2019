#include "circle.hpp"
#include <iostream>
#include <cmath>

Circle::Circle(double radius, const point_t &center):
  center_(center),
  radius_(radius)
{
  if (radius<=0)
  {
    std::cerr << "Incorrect radius" << std::endl;
  }
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

void Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::move(const point_t &center)
{
  center_ = center;
}

rectangle_t Circle::getFrameRect() const
{
  return rectangle_t{center_, radius_ * 2, radius_ * 2};
}
