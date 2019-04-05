#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

Circle::Circle(const point_t &center, double radius) :
  center_(center),
  radius_(radius)
{
  assert(radius >= 0);
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
