#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(rectangle_t rectangle):
  rectangle_(rectangle)
{
  assert((rectangle_.height > 0) && (rectangle_.width > 0));
}

double Rectangle::getArea() const
{
  return rectangle_.height * rectangle_.width;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_;
}

void Rectangle::move(const double dx, const double dy)
{
  rectangle_.pos.x += dx;
  rectangle_.pos.y += dy;
}

void Rectangle::move(const point_t &point)
{
  rectangle_.pos = point;
}
