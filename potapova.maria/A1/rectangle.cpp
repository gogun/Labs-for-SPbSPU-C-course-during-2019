#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t &center, double height, double width):
  rectangle_({center, height, width})
{
  assert((height > 0) && (width > 0));
}

double Rectangle::getArea() const
{
  return rectangle_.height * rectangle_.width;
}

void Rectangle::move(double dx, double dy)
{
  rectangle_.pos.x += dx;
  rectangle_.pos.y += dy;
}

void Rectangle::move(const point_t &center)
{
  rectangle_.pos = center;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_;
}
