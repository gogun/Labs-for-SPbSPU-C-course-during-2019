#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t & center, double width, double height) :
  rect_({center, width, height})
{
  assert((rect_.width > 0) && (rect_.height > 0));
}

double Rectangle::getArea() const
{
  return rect_.height * rect_.width;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}

void Rectangle::move(const point_t & newCenter)
{
  rect_.pos = newCenter;
}
  
void Rectangle::move(double dispX, double dispY)
{
  rect_.pos.x += dispX;
  rect_.pos.y += dispY;
}
