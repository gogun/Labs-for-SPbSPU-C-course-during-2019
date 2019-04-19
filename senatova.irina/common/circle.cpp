#include "circle.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

senatova::Circle::Circle(const point_t pos, double radius):
  pos_(pos),
  radius_(radius)
{
  if (radius_ < 0)
  {
    throw std::invalid_argument("Invalid radius");
  }
}

double senatova::Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

senatova::rectangle_t senatova::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, pos_};
}

void senatova::Circle::move(const point_t &point)
{
  pos_ = point;
}

void senatova::Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void senatova::Circle::scale(const double multiplier)
{
  if (multiplier <= 0)
  {
    throw std::invalid_argument("Invalid multiplier");
  }
  radius_ *= multiplier;
}

void senatova::Circle::print() const
{
  std::cout << "Area: " << getArea() << std::endl;
  std::cout << "Center position x = " << pos_.x << std::endl;
  std::cout << "Center position y = " << pos_.y << std::endl;
  rectangle_t frame = getFrameRect();
  std::cout << "Circle frame: " << std::endl;
  std::cout << "Height: " << frame.height << std::endl;
  std::cout << "Width: " << frame.width << "\n\n";
}
