#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const rectangle_t & rect) :
  rect_(rect)
{
  assert((rect.width > 0) && (rect.height > 0));
}

double  Rectangle::getArea() const
{
  return (rect_.height * rect_.width);
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}

void Rectangle::move(const point_t & point)
{
  rect_.pos = point;
}

void Rectangle::move(double x, double y)
{
  rect_.pos.x += x;
  rect_.pos.y += y;
};