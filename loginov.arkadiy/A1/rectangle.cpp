#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const point_t &point, double const width, double const height):
        rectangle_({ width, height, point })
{
  assert(width > 0.0 && height > 0.0);
}

double Rectangle::getArea() const
{
  return rectangle_.width * rectangle_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_;
}

void Rectangle::move(double dx, double dy)
{
  rectangle_.pos.x += dx;
  rectangle_.pos.y += dy;
}

void Rectangle::move(const point_t &point)
{
  rectangle_.pos = point;
}
