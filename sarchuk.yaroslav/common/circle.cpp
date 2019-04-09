#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

sarchuk::Circle::Circle(point_t position, double radius) :
  pos_(position),
  radius_(radius)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Radius must be more than 0");
  }
}

double sarchuk::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

void sarchuk::Circle::writeInfo() const
{
  std::cout << "Circle info:\n"
            << "Radius - " << radius_ << "\n"
            << "Center position - x = " << pos_.x << ", y = " << pos_.y << "\n"
            << "Area - " << getArea() << "\n\n";
}

void sarchuk::Circle::move(point_t pos)
{
  pos_ = pos;
}

void sarchuk::Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

rectangle_t sarchuk::Circle::getFrameRect() const
{
  return {pos_, 2 * radius_, 2 * radius_};
}

void sarchuk::Circle::scale(double mult)
{
  if (mult <= 0)
  {
    throw std::invalid_argument("Multiplier must be more than 0");
  }

  radius_ *= mult;

}
