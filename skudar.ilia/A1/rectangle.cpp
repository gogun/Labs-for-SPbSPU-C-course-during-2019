#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(point_t pos, double w, double h):
  center_(pos),
  width_(w),
  height_(h)
{
  assert((width_ > 0) && (height_ > 0));
}

Rectangle::Rectangle(double x, double y, double w, double h):
  Rectangle({x, y}, w, h)
{
  assert((width_ > 0) && (height_ > 0));
}

void Rectangle::move(point_t point)
{
  center_ = point;
}

void Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {center_, width_, height_};
}
