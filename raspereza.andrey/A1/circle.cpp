#include <iostream>
#include "circle.hpp"
#include <cassert>
#include <cmath>

Circle::Circle(point_t dot, double radius):
  center_(dot),
  radius_(radius)
{
  assert(radius_ >= 0.0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

void Circle::printInfo() const
{
  std::cout << "Center= " << center_.x << ";" << center_.y << " Radius= " << radius_ << "\n";
}

rectangle_t Circle::getFrameRect() const
{
  return {radius_ * 2,radius_ * 2,center_};
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
