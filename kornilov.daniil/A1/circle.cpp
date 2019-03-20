#define _USE_MATH_DEFINES

#include "circle.hpp"
#include <iostream>
#include <cmath>

Circle::Circle(double radius, double x, double y)
{
  radius_ = radius;
  pos_.x = x;
  pos_.y = y;
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Invalid circle radius!");
  }
}

double Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

rectangle_t Circle::getFrameRect() const
{
  rectangle_t rectangle;
  rectangle.pos = pos_;
  rectangle.height = radius_ * 2;
  rectangle.width = radius_ * 2;
  return rectangle;
}

void Circle::move(const point_t &point)
{
  pos_ = point;
}

void Circle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}