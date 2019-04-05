#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const rectangle_t &parameters):
  rectangle_(parameters)
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
  rectangle_.centre.x += dx;
  rectangle_.centre.y += dy;
}

void Rectangle::move(const point_t &point)
{
  rectangle_.centre = point;
}
