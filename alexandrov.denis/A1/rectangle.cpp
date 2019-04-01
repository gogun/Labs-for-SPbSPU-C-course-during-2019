#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const rectangle_t & rect):
  rect_(rect)
{
  assert(rect_.height > 0.0 || rect_.width > 0.0);
}

void Rectangle::move(const point_t & newPoint)
{
  rect_.pos = newPoint;
}

void Rectangle::move(const double dx, const double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

double Rectangle::getArea() const
{
  return rect_.height * rect_.width;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}
