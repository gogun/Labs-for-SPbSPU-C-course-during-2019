#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>
#include "base-types.hpp"

borshchev::Circle::Circle(const point_t & center, const double radius) :
  radius_(radius),
  center_(center)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Incorrect value, RADIUS should be positive");
  }
}

double borshchev::Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

borshchev::rectangle_t borshchev::Circle::getFrameRect() const
{
  return { center_, radius_ * 2, radius_ * 2 };
}

void borshchev::Circle::move(const double newX, const double newY)
{
  center_.x += newX;
  center_.y += newY;
}

void borshchev::Circle::move(const point_t &point)
{
  center_ = point;
}

void borshchev::Circle::dataOutput() const
{
  std::cout << "Circle's RADIUS: " << radius_ << '\n'
    << "Circle's CENTER: " << center_.x << " " << center_.y << '\n';
}

void borshchev::Circle::scale(double scalingCoefficient)
{
  if (scalingCoefficient <= 0)
  {
    throw std::invalid_argument("Incorrect value, scaling COEFFICIENT should be positive");
  }
  radius_ *= scalingCoefficient;
}
