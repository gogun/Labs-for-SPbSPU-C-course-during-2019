#include "rectangle.hpp"

#include <cassert>

Rectangle::Rectangle(double w, double h, point_t p):
  Shape(p),
  width_(w),
  height_(h)
{
  assert((height_ > 0) && (width_ > 0));
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, centre_};
}
