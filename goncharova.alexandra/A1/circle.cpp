#define _USE_MATH_DEFINES

#include "circle.hpp"
#include <cmath>
#include <cassert>
#include <iostream>

Circle::Circle(const point_t &center, const double radius) :
  center_(center),
  radius_(radius)
{
  assert(radius_ > 0.0);
}

rectangle_t Circle::getFrameRect() const
{
  return { center_, radius_ * 2, radius_ * 2 };
}

double Circle::getArea() const
{
  return radius_ * radius_* M_PI;
}

void Circle::move(const double dx, const double dy)

{
  center_.x = center_.x + dx;
  center_.y = center_.y + dy;
}

void Circle::move(const point_t &newPoint)
{
  center_ = newPoint;
}
