#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <cassert>
#include "circle.hpp"

Circle::Circle(const double radius, const point_t & center):
  radius_(radius),
  center_(center)
{
  assert((radius_ > 0) && ("Error. Incorrect radius of circle."));
}

double Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
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

void Circle::print() const
{
  std::cout << "Area of circle: " << getArea() << "\n";
  std::cout << "Width of frame rectangle: " << getFrameRect().width << "\n";
  std::cout << "Height of frame rectangle: " << getFrameRect().height << "\n";
  std::cout << "Center point of frame rectangle: (" << getFrameRect().pos.x
            << "; " << getFrameRect().pos.y << ")" << "\n";
}
