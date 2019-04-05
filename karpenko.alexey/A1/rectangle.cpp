#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const rectangle_t &rect) :
  rect_(rect)
{
  assert((rect.width > 0.0)&&(rect.height > 0.0));
}

double Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}

void Rectangle::move(const double dx, const double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void Rectangle::move(const point_t &newPos)
{
  rect_.pos = newPos;
}
