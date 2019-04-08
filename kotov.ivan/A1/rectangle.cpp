#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t & center, double widht, double heigth) :
  rect_({center, widht, heigth})
{
  assert((rect_.width > 0) && (rect_.height > 0));
}

std::string Rectangle::getShapeName() const
{
  return "rectangle";
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
  
void Rectangle::move(double dX, double dY)
{
  rect_.pos.x += dX;
  rect_.pos.y += dY;
}
