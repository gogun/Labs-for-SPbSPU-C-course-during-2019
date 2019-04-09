#include "circle.hpp"
#include <cmath>
#include <stdexcept>

kornilov::Circle::Circle(const point_t &centre, double radius):
  pos_(centre),
  radius_(radius)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Invalid radius!");
  }
}

double kornilov::Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

kornilov::rectangle_t kornilov::Circle::getFrameRect() const
{
  return {pos_, radius_ * 2, radius_ * 2};
}

void kornilov::Circle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void kornilov::Circle::move(const point_t &point)
{
  pos_ = point;
}

void kornilov::Circle::scale(const double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Invalid coefficient!");
  }
  radius_ *= coefficient;
}
