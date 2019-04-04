#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(double width, double height, const point_t & pos):
rect_ (rectangle_t { .width = width, .height = height, .pos = pos })
{
    assert ((width > 0.0) &&(height > 0.0));
}

double Rectangle::getArea() const
{
  return(rect_.width * rect_.height);
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}

void Rectangle::move(const point_t & pos)
{
  rect_.pos.x = pos.x;
  rect_.pos.y = pos.y;
}

void Rectangle::move(double x, double y)
{
  rect_.pos.x += x;
  rect_.pos.y += y;
}
