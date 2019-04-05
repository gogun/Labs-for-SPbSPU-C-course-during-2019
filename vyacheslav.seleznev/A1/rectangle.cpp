#include "rectangle.hpp"

#include <cassert>

Rectangle::Rectangle(double width, double height, point_t pos)
{
  assert(width > 0);
  assert(height > 0);

  this->width = width;
  this->height = height;
  this->centre = pos;
}

double Rectangle::getArea() const
{
  return this->width * height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {this->width, this->height, centre};
}
