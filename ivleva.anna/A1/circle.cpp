#include "circle.hpp"
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <cmath>

Circle::Circle(double radius, const point_t & center):
  radius_(radius),
  center_(center)
{
  assert(radius > 0);
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

void Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::print() const
{
  std::cout << "Area of circle: " << getArea() << std::endl;
  std::cout << "Width of frame rectangle: " << getFrameRect().width << std::endl;
  std::cout << "Height of frame rectangle: " << getFrameRect().height << std::endl;
  std::cout << "Center point of frame rectangle: (" << getFrameRect().pos.x
  << "; " << getFrameRect().pos.y << ")" << std::endl;
}
