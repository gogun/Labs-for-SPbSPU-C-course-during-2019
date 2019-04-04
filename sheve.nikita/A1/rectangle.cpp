#include "rectangle.hpp"
#include <stdlib.h>
#include <math.h>

Rectangle::Rectangle(const point_t &p, double w, double h):
  pos (p),
  width (w),
  height (h)
{
  if (width <= 0)
  {
    std::cerr << "Invalid rectangle width.\n";
    exit(1);
  }
  if (height <= 0){
    std::cerr << "Invalid rectangle height.\n";
    exit(1);
  }
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

void Rectangle::move (const point_t &p)
{
  pos = p;
}

void Rectangle::move (const double dx, const double dy)
{
  pos.x += dx;
  pos.y += dy;
}
