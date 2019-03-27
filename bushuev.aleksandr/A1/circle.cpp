#define _USE_MATH_DEFINES
#include "circle.hpp"
#include "iostream"
#include <math.h>

Circle::Circle(const point_t &center,double radius)
{
  Circle(center.x,center.y,radius);
}

Circle::Circle(double center_x,double center_y,double radius)
{
  center_.x = center_x;
  center_.y = center_y;
  radius_ = radius;
  if (radius<=0)
  {
    std::cerr << "Radius must be > 0";
  }
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

void Circle::coutInfo() const
{
  std::cout << "Circle at " << "(" << center_.x << "," << center_.y << ")" << std::endl;
  std::cout << "Radius: " << radius_ << std::endl;
  std::cout << "Area: " << getArea() << std::endl;
}

void Circle::move(double x,double y)
{
  center_.x+=x;
  center_.y+=y;
}

void Circle::move(const point_t &pos)
{
  center_ = pos;
}
