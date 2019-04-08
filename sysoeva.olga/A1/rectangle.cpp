#include "rectangle.hpp"
#include <cassert>
#include <iostream>

Rectangle::Rectangle(const point_t & point, const double height, const double width)
{
  assert((height > 0.0) && (width > 0.0));
  rect.pos = point;
  rect.height = height;
  rect.width = width;
}

double Rectangle::getArea() const
{
  return rect.width * rect.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect;
}

void Rectangle::move(const point_t & point)
{
  rect.pos = point;
}

void Rectangle::move(const double dx, const double dy)
{
  rect.pos.x += dx;
  rect.pos.y += dy;
}
