#include "circle.hpp"
#include <iostream>
#include <cassert>
#include <math.h>

Circle::Circle(const point_t &center,const double radius) :
  center_(center),
  radius_(radius)
{
  assert(radius > 0.0);
}

double Circle::getArea() const
{
  return M_PI*radius_*radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {2*radius_,2*radius_,center_};
}

void Circle::move(const double dx,const double dy)
{
  center_.x+=dx;
  center_.y+=dy;
}

void Circle::move(const point_t &newPos)
{
  center_ = newPos;
}

void Circle::printInfo() const
{
  std::cout << "Circle at " << "(" << center_.x << "," << center_.y << ")" << std::endl;
  std::cout << "Radius: " << radius_ << std::endl;
  std::cout << "Area: " << getArea() << std::endl;
}
