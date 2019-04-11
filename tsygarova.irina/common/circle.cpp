#include "circle.hpp"

#include <iostream>
#include <stdexcept>
#include <cmath>

tsygarova::Circle::Circle(const double radius, const point_t & center):
  radius_(radius),
  center_(center)
{
  if (radius_ < 0.0) 
  {
    throw std::invalid_argument("Error. Invalid radius of circle.\n");
  }
}

double tsygarova::Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

tsygarova::rectangle_t tsygarova::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void tsygarova::Circle::move(const point_t & point)
{
  center_ = point;
}

void tsygarova::Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void tsygarova::Circle::print() const
{
  std::cout << "Area of circle: " << getArea() << std::endl;
  std::cout << "Width of frame rectangle: " << getFrameRect().width << std::endl;
  std::cout << "Height of frame rectangle: " << getFrameRect().height << std::endl;
  std::cout << "Center point of frame rectangle: (" << getFrameRect().pos.x
            << "; " << getFrameRect().pos.y << ")" << std::endl;
}

void tsygarova::Circle::scale(const double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Error.Invalid coefficient of scale\n");
  }
  radius_ *= coefficient;
}
