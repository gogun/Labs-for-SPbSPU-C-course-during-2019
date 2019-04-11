#include "rectangle.hpp"
#include <stdlib.h>
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t &p, double w, double h):
  pos(p),
  width(w),
  height(h)
{
  assert((width > 0.0) && (height > 0.0));
}

double Rectangle::getArea() const
{
  return (width * height);
}

rectangle_t Rectangle::getFrameRect() const
{
  rectangle_t localRect;
  localRect.pos.x = pos.x;
  localRect.pos.y = pos.y;
  localRect.width  = width;
  localRect.height = height;
  return localRect;
}

void Rectangle::move(const point_t &p)
{
  pos = p;
}

void Rectangle::move(double dx, double dy)
{
  pos.x += dx;
  pos.y += dy;
}
