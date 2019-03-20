#include "circle.hpp"

#include <math.h>
#include <iostream>

Circle::Circle(point_t pos, double r) : center_(pos), radius_(r)
{
  if (radius_ <= 0) {
    std::cerr << "Circle: Invalid dimensions\n";
  }
}

Circle::Circle(double x, double y, double r) : Circle({x, y}, r)
{ }

Circle::Circle() : Circle({0, 0}, 0)
{}

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
  rectangle_t tmp = {radius_ * 2, radius_ * 2, center_};
  return tmp;
}
