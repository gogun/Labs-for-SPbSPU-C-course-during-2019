#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <stdexcept>


karpenko::Circle::Circle(const double radius, const point_t & center) :
  center_(center),
  radius_(radius)
{
  if (radius <= 0.0)
  {
    throw std::invalid_argument("Radius must be positive number");
  }
}

double karpenko::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

karpenko::rectangle_t karpenko::Circle::getFrameRect() const
{
  return { radius_ * 2, radius_ * 2 ,center_ };
}

void karpenko::Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void karpenko::Circle::move(const point_t & newPos)
{
  center_ = newPos;
}

void karpenko::Circle::scale(double scaleRatio)
{
  if (scaleRatio < 0)
  {
    throw std::invalid_argument("scaleRatio should be positive value!");
  }
  radius_ *= scaleRatio;
}
