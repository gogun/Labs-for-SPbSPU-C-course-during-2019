#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t & center, double widht, double heigth) :
  rect_({center, widht, heigth})
{
  assert((rect_.widht > 0) && (rect_.heigth > 0));
}

double Rectangle::getArea() const
{
  return rect_.heigth * rect_.widht;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}

void Rectangle::move(const point_t & newCenter)
{
  rect_.pos = newCenter;
}
  
void Rectangle::move(double dX, double dY)
{
  rect_.pos.x += dX;
  rect_.pos.y += dY;
}
