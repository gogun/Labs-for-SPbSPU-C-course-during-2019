#include "circle.hpp"
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <cmath>

ivleva::Circle::Circle(double radius, const point_t & center):
  radius_(radius),
  center_(center)
{
  assert(radius > 0);
}

double ivleva::Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

ivleva::rectangle_t ivleva::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void ivleva::Circle::move(const point_t & point)
{
  center_ = point;
}

void ivleva::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void ivleva::Circle::print() const
{
  std::cout << "Area of circle: " << getArea() << std::endl;
  std::cout << "Width of frame rectangle: " << getFrameRect().width << std::endl;
  std::cout << "Height of frame rectangle: " << getFrameRect().height << std::endl;
  std::cout << "Center point of frame rectangle: (" << getFrameRect().pos.x
  << "; " << getFrameRect().pos.y << ")" << std::endl;
}

void ivleva::Circle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("The coefficient need to be positive");
  }
  radius_ *= coefficient;
}
