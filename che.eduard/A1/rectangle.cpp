#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const rectangle_t & rect):
  rect_(rect)
{
  assert((rect_.height > 0.0) && (rect_.width > 0.0));
}

double Rectangle::getArea() const
{
  return rect_.height * rect_.width;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}

void Rectangle::move(double dx, double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void Rectangle::move(const point_t & point)
{
  rect_.pos = point;
}

