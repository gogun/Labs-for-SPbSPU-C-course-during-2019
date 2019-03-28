#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "circle.h"

Circle::Circle(double radius, const point_t &center) :
  radius_(radius), 
  center_(center)
{
  if (radius_ <= 0.0)
  {
    std::cerr << "Invalid circle radius" << std::endl;
  }
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return { radius_ * 2, radius_ * 2, center_ };
}

void Circle::move(const point_t &newPos)
{
  center_ = newPos;
}

void Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

point_t Circle::getPos() const
{
  return center_;
}