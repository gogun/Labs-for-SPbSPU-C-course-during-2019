#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

firsov::Circle::Circle(const double radius, const point_t& position):
  radius_(radius),
  pos_(position)
{
  if (radius_ < 0)
  {
    throw std::invalid_argument("Invalid radius");
  }
}

double firsov::Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

firsov::rectangle_t firsov::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, pos_};
}

void firsov::Circle::move(const point_t& point)
{
  pos_ = point;
}

void firsov::Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}


void firsov::Circle::scale(const double multiplier)
{
  if (multiplier <= 0)
  {
    throw std::invalid_argument("Invalid multiplier");
  }
  radius_ *= multiplier;
}


void firsov::Circle::printShapeInfo() const
{
  std::cout << "Radius: " << radius_ << std::endl;
  std::cout << "Center position x = " << pos_.x << ", y = " << pos_.y << std::endl;
  std::cout << "Area: " << getArea() << std::endl;
  rectangle_t frame = getFrameRect();
  std::cout << "Circle frame: " << std::endl;
  std::cout << "Width: " << frame.width << std::endl;
  std::cout << "Height: " << frame.height << "\n\n";
}
