#include "circle.hpp"
#include <math.h>
#include <iostream>
#include <cassert>

Circle::Circle (double radius, point_t pos):
  Shape(pos),
  radius_(radius)
{
  assert(radius > 0.0);
}

void Circle::displayData() const
{
  std::cout << "\nRadius: " << radius_;
  Shape::displayData();
}

double Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return rectangle_t{radius_ * 2, radius_ * 2, {pos_.x, pos_.y}};
}
