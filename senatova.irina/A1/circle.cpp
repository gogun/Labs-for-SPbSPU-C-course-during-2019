#include "circle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

Circle::Circle(const point_t pos, double radius):
  radius_(radius),
  pos_(pos)
{
  assert(radius > 0.0);
}

double Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, pos_};
}

void Circle::move(const point_t &point)
{
  pos_ = point;
}

void Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Circle::print() const
{
  std::cout << "Area: " << getArea() << std::endl;
  std::cout << "Center position x = " << pos_.x << std::endl;
  std::cout << "Center position y = " << pos_.y << std::endl;
  rectangle_t frame = getFrameRect();
  std::cout << "Circle frame: " << std::endl;
  std::cout << "Height: " << frame.height << std::endl;
  std::cout << "Width: " << frame.width << "\n\n";
}
