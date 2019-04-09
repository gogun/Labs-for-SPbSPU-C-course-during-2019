#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <iostream>
#include "base-types.hpp"
#include <cmath>
#include <cassert>

Circle::Circle(const point_t center, const double radius) :
  radius_(radius),
  center_(center)
{
  assert(radius > 0.0);
}

double Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return { center_, radius_ * 2, radius_ * 2 };
}

void Circle::move(const double newX, const double newY)
{
  center_.x += newX;
  center_.y += newY;
}

void Circle::move(const point_t & point)
{
  center_ = point;
}

void Circle::dataOutput() const
{
  std::cout << "Circle's RADIUS: " << radius_ << '\n'
    << "Circle's CENTER: " << center_.x << " " << center_.y << '\n';
}
