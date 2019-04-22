#include "circle.hpp"
#include <math.h>
#include <stdexcept>
#include <iostream>

shestakova::Circle::Circle(point_t pos, double radius) :
  pos_(pos),
  radius_(radius)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Circle's radius can't be negative.");
  }
}

double shestakova::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

shestakova::rectangle_t shestakova::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, pos_};
}

void shestakova::Circle::move(const point_t &point)
{
  pos_ = point;
}

void shestakova::Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void shestakova::Circle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Coefficient can't be negative.");
  }
  radius_ *= coefficient;
}
