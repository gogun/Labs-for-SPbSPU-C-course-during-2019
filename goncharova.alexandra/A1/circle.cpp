#include "circle.hpp"
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cassert>

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
  center_.x += dx;
  center_.y += dy;
}

void Circle::move(const point_t &newPoint)
{
  center_ = newPoint;
}
