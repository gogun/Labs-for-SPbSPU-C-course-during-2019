#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

akhmedov::Circle::Circle(const point_t &pos, double radius):
  pos_(pos),
  radius_(radius)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Radius is surely invalid");
  }
}

double akhmedov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

akhmedov::rectangle_t akhmedov::Circle::getFrameRect() const
{
  return { pos_, 2 * radius_, 2 * radius_ };
}

void akhmedov::Circle::move(const point_t &pos)
{
  pos_ = pos;
}

void akhmedov::Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void akhmedov::Circle::printInfo() const
{
  std::cout << "X center is: " << pos_.x << std::endl;
  std::cout << "Y center is: " << pos_.y << std::endl;
  std::cout << "Radius is: " << radius_ << std::endl;
}

akhmedov::point_t akhmedov::Circle::getCenter() const
{
  return pos_;
}

void akhmedov::Circle::scale(double multiplyCoefficient)
{
  if (multiplyCoefficient <= 0)
  {
    throw std::invalid_argument("Multiply Coefficient is surely invalid");
  }
  radius_ *= multiplyCoefficient;
}

double akhmedov::Circle::getRadius() const
{
  return radius_;
}
