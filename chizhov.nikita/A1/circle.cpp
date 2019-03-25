#include "circle.hpp"

#include <math.h>
#include <iostream>

Circle::Circle(point_t pos, double r) :
    center_(pos),
    radius_(r)
{
  if (radius_ <= 0) {
    std::cerr << "Circle: Invalid dimensions\n";
  }
}

Circle::Circle(double x, double y, double r) :
    Circle({x, y}, r)
{ }

Circle::Circle() :
    center_({0, 0}),
    radius_(0)
{ }

void Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::move(point_t point)
{
  center_ = point;
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, center_};
}
