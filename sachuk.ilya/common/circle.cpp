#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

sachuk::Circle::Circle(const point_t & point, double rad):
  center_(point),
  radius_(rad)
{
  if (radius_ <= 0) {
    throw std::invalid_argument("Invalid argument");
  }
}

double sachuk::Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

void sachuk::Circle::move(const point_t & point)
{
  center_ = point;
}

void sachuk::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

sachuk::rectangle_t sachuk::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void sachuk::Circle::scale(double multiplier)
{
  if (multiplier <= 0) {
    throw std::invalid_argument("Multiplier must be positive");
  } else {
    radius_ *= multiplier;
  }
}

void sachuk::Circle::printInfo() const
{
  std::cout << "Circle:" << std::endl;
  std::cout << "Radius:" << radius_ << std::endl;
  std::cout << "X=" << center_.x << ";";
  std::cout << "Y=" << center_.y << std::endl;
  std::cout << "Area=" << getArea() << std::endl;
  std::cout << "Frame Rect:" << std::endl;
  std::cout << "Width" << getFrameRect().width << ";";
  std::cout << "Height" << getFrameRect().height << std::endl;
  std::cout << "X=" << getFrameRect().pos.x << ";";
  std::cout << "Y=" << getFrameRect().pos.y << std::endl << std::endl;
}
