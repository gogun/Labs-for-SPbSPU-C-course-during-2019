#include <iostream>
#include <string>
#include <cassert>
#include "rectangle.hpp"

Rectangle::Rectangle(const point_t center, const double width, const double height):
  rectangle_({center, width, height})
{
  assert((width > 0.0) && (height > 0.0));
}

double Rectangle::getArea() const
{
  return rectangle_.width * rectangle_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_;
}

void Rectangle::move(const point_t new_center)
{
  rectangle_.pos = new_center;
}

void Rectangle::move(double dx, double dy)
{
  rectangle_.pos.x += dx;
  rectangle_.pos.y += dy;
}
