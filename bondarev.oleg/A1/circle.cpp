#include "circle.hpp"
#include <cassert>
#define _USE_MATH_DEFINES
#include <math.h>

Circle::Circle(const point_t &center, double radius) :
  center_(center),
  radius_(radius)
{
  assert(radius_ >= 0.0);
}

double Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return { center_, radius_ * 2, radius_ * 2 };
}

void Circle::move(const point_t &newCenter)
{
  center_ = newCenter;
}

void Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

point_t Circle::getPos() const
{
  return center_;
};
