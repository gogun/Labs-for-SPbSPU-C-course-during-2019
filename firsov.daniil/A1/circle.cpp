#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

Circle::Circle(const double radius, const point_t& position):
  radius_(radius),
  pos_(position)
{
  assert (radius > 0.0);
}

double Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, pos_};
}

void Circle::move(const point_t& point)
{
  pos_ = point;
}

void Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Circle::printShapeInfo() const
{
  std::cout << "Radius: " << radius_ << std::endl;
  std::cout << "Center position x = " << pos_.x << ", y = " << pos_.y << std::endl;
  std::cout << "Area: " << getArea() << std::endl;
  rectangle_t frame = getFrameRect();
  std::cout << "Circle frame: " << std::endl;
  std::cout << "Width: " << frame.width << std::endl;
  std::cout << "Height: " << frame.height << "\n\n";
}

