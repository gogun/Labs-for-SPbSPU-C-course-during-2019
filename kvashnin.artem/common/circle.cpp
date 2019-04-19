#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <cmath>
#include <iostream>

kvashnin::Circle::Circle(const point_t &position, const double radius):
  pos_(position),
  radius_(radius)
{
  if (radius < 0)
  {
    throw std::invalid_argument("radius can not be < 0");
  }
}

double kvashnin::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

void kvashnin::Circle::move(const point_t &pos)
{
  pos_ = pos;
}

void kvashnin::Circle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

kvashnin::rectangle_t kvashnin::Circle::getFrameRect() const
{
  return {pos_, 2 * radius_, 2 * radius_};
}

void kvashnin::Circle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("coefficient can not be <= 0");
  }
  radius_ *= coefficient;
}

void kvashnin::Circle::printInfo() const
{
  rectangle_t FrameRectData = getFrameRect();
  std::cout << "Circle coordinates: X: " << pos_.x
      << "; Y: " << pos_.y << std::endl
      << "Circle area: " << getArea() << std::endl
      << "Circle radius: " << radius_ << std::endl
      << "Rectangle frame width: " << FrameRectData.width
      << "; height: " << FrameRectData.height << std::endl;
}
