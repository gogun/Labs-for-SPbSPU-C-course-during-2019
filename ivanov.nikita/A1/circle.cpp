#define _USE_MATH_DEFINES
#include <iostream>
#include <cassert>
#include <math.h>
#include "circle.hpp"

Circle::Circle(const double radius, const point_t &center):
  radius_(radius),
  center_(center)
{
  assert((radius_ > 0) && ("Incorrect radius"));
}

double Circle::getArea() const
{
  return (radius_ * radius_* M_PI);
}

rectangle_t Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ *2 , center_};
}

void Circle::move(const point_t & point)
{
  center_ = point;
}

void Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::draw() const
{ 
  std::cout << "Width of frame rectangle: " << getFrameRect().width << "\n";
  std::cout << "Height of frame rectangle: " << getFrameRect().height << "\n";
  std::cout << "Area of circle: " << getArea() << "\n";
  std::cout << "Center of frame rectangle: (" << getFrameRect().pos.x
            << "; " << getFrameRect().pos.y << ")" << "\n";
}
