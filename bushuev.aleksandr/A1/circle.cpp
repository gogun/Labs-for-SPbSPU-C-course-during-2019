#include "circle.hpp"
#include "iostream"
#include <cassert>
#include <math.h>

Circle::Circle(const point_t &center,const double radius) :
  center_(center),
  radius_(radius)
{
  assert(radius_ > 0.0);
}

double Circle::getArea() const
{
  return M_PI*radius_*radius_;
}

rectangle_t Circle::getFrameRect() const
{
  rectangle_t rect = {2*radius_,2*radius_,center_};
  return rect;
}

void Circle::printInfo() const
{
  std::cout << "Circle at " << "(" << center_.x << "," << center_.y << ")" << std::endl;
  std::cout << "Radius: " << radius_ << std::endl;
  std::cout << "Area: " << getArea() << std::endl;
}

void Circle::move(const double x,const double y)
{
  center_.x+=x;
  center_.y+=y;
}

void Circle::move(const point_t &pos)
{
  center_ = pos;
}
