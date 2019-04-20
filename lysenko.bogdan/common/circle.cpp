#include "circle.hpp"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

lysenko::Circle::Circle(const double radius, const point_t & center):
  radius_(radius),
  center_(center)
{
  if (radius_ <= 0.0)
  {
    throw std::invalid_argument("Error. Incorrect radius of circle.");
  }
}

double lysenko::Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

lysenko::rectangle_t lysenko::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void lysenko::Circle::move(const point_t & point)
{
  center_ = point;
}

void lysenko::Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void lysenko::Circle::print() const
{
  std::cout << "Area of circle: " << getArea() << "\n";
  std::cout << "Width of frame rectangle: " << getFrameRect().width << "\n";
  std::cout << "Height of frame rectangle: " << getFrameRect().height << "\n";
  std::cout << "Center point of frame rectangle: (" << getFrameRect().pos.x
            << "; " << getFrameRect().pos.y << ")" << "\n";
}

void lysenko::Circle::scale(const double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Error.Incorrect coefficient of scale.");
  }
  else
  {
    radius_*= coefficient;
  }
}
