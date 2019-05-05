#include "circle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

atamanova::Circle::Circle(point_t center, double radius) :
  center_(center),
  radius_(radius)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Radius is less or equal 0");
  }
}


void atamanova::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void atamanova::Circle::move(point_t point)
{
  center_ = point;
}

double atamanova::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

atamanova::rectangle_t atamanova::Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, center_};
}

void atamanova::Circle::scale(double scale)
{
  if (scale <= 0)
  {
    throw std::invalid_argument("Scale is less or equal 0");
  }
  else
  {
    radius_ *= scale;
  }
}
