#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <cmath>
#include <iostream>
#include <stdexcept>

kurbanova::Circle::Circle(const point_t &center, double rad):
  pos_(center),
  radius_(rad)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Invalid radius");
  }
}

double kurbanova::Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

kurbanova::rectangle_t 
kurbanova::Circle::getFrameRect() const
{
  return {pos_, 2 * radius_, 2 * radius_};
}

void kurbanova::Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void kurbanova::Circle::move(const point_t &pos1)
{
  pos_ = pos1;
}

void kurbanova::Circle::scale(double coefficient)
{
  if (coefficient > 0)
  {
    radius_ *= coefficient;
  }
  else
  {
    throw std::invalid_argument("Invalid circle's coefficient");
  }
}

void kurbanova::Circle::printInfo() const
{
  std::cout << "Area = " << getArea() << "\n"
            << "Radius = " << radius_ << "\n"
            << "Position (" << pos_.x << ", " << pos_.y << ")\n";
}

kurbanova::point_t kurbanova::Circle::getCenter() const
{
  return pos_;
}

double kurbanova::Circle::getRad() const
{
  return radius_;
}
