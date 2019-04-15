#include "circle.hpp"
#include <iostream>
#include <cassert>

const double PI = 3.141593;

Circle::Circle(const point_t center, const double radius)
{
  assert(radius > 0);
  center_ = center;
  radius_ = radius;
}

double Circle::getArea() const
{
  return PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return { 2 * radius_, 2 * radius_, center_ };
}

void Circle::move(const point_t point)
{
  center_ = point;
}

void Circle::move(const double x, const double y)
{
  center_.x += x;
  center_.y += y;
}

void Circle::getInfo() const
{
  std::cout << "\nRadius of circle is: " << radius_ << std::endl;
  std::cout << "Center of circle is: x=" << center_.x << " y=" << center_.y << std::endl;
}
