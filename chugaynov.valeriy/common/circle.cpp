#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <cmath>
#include <iostream>

chugaynov::Circle::Circle(const point_t &point, double radius):
  pos_(point),
  radius_(radius)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("\nThe circle's radius must be positive\n");
  }
}

double chugaynov::Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

double chugaynov::Circle::getRadius()
{
  return radius_;
}

chugaynov::rectangle_t chugaynov::Circle::getFrameRect() const
{
  return { pos_, radius_ * 2, radius_ * 2, };
}

void chugaynov::Circle::move(const point_t &point)
{
  pos_ = point;
}

void chugaynov::Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void chugaynov::Circle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("\nScaling coefficient must be positive\n");
  }
  radius_ *= coefficient;
}
