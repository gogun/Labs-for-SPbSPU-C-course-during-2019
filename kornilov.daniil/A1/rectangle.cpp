#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(double width, double height, const point_t &centre)
{
  assert((height > 0) and (width > 0));
  parameters_.height = height;
  parameters_.width = width;
  parameters_.pos = centre;
}

double Rectangle::getArea() const
{
  return parameters_.height*parameters_.width;
}

rectangle_t Rectangle::getFrameRect() const
{
  return parameters_;
}

void Rectangle::move(const double dx, const double dy)
{
  parameters_.pos.x += dx;
  parameters_.pos.y += dy;
}

void Rectangle::move(const point_t &point)
{
  parameters_.pos = point;
}
