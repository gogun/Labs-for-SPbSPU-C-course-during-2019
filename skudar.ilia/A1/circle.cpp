#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

Circle::Circle(point_t pos, double r):
  center_(pos),
  radius_(r)
{
/*  if (r <= 0) {
    std::cerr << "Invalid radius of circle" << std::endl;
  }*/
  assert(r > 0);
}

Circle::Circle(double x, double y, double r):
  Circle({x, y}, r)
{ }

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {center_, 2 * radius_, 2 * radius_};
}

void Circle::move(point_t point)
{
  center_ = point;
}

void Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}
