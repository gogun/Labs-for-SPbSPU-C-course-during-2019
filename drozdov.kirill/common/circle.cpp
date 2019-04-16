#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <math.h>
#include <iostream>
#include <stdexcept>

drozdov::Circle::Circle (double radius, const point_t &pos):
  radius_(radius),
  pos_(pos)
{
  if (radius <= 0.0) {
    throw std::invalid_argument("Circle's arguments are not valid.");
  }
}

void drozdov::Circle::printData() const
{
  std::cout << "\nRadius: " << radius_;
  std::cout << "\nPosition: (" << pos_.x << ';' << pos_.y << ')' << std::endl;
}

double drozdov::Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

drozdov::rectangle_t drozdov::Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, pos_};
}

void drozdov::Circle::scale(double coefficient)
{
  if (coefficient > 0.0) {
    radius_ *= coefficient;
  } else {
    throw std::invalid_argument("\nCircle's coefficient for scale is not valid.");
  }
}

double drozdov::Circle::getRadius() const
{
  return radius_;
}

void drozdov::Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void drozdov::Circle::move(const point_t &newPos)
{
  pos_ = newPos;
}
