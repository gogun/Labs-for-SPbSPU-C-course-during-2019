#include "circle.hpp"
#include <cmath>
#include <iostream>
#include <cassert>

Circle::Circle(const point_t & center, double radius) :
  center_(center),
  radius_(radius)
{
  assert(radius_ > 0);
}

std::string Circle::getShapeName() const
{
  return "circle";
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {center_, 2 * radius_, 2 * radius_};
}

void Circle::move(const point_t & newCenter)
{
  center_ = newCenter;
}

void Circle::move(double dX, double dY)
{
  center_.x += dX;
  center_.y += dY;
}
