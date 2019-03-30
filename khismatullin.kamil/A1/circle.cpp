#include "circle.hpp"
#include <iostream>
#include <cassert>
#include <math.h>
#include "shape.hpp"


Circle::Circle(const point_t &pos, const double radius) :
    center_(pos),
    radius_(radius)
{
  assert(radius > 0);
}

double Circle::getArea() const
{
  return pow(radius_, 2) * M_PI;
}

rectangle_t Circle::getFrameRect() const
{
  return {center_, radius_ * 2, radius_ * 2};
}

void Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::move(const point_t &point)
{
  center_ = point;
}

point_t Circle::getCenter() const
{
  return center_;
}

double Circle::getRadius() const
{
  return radius_;
}
