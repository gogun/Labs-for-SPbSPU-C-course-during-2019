#include <iostream>
#include <cassert>
#include "rectangle.hpp"

Rectangle:: Rectangle(double w, double h, point_t c):
  width_(w),
  height_(h),
  center_(c)
{
  assert ((width_ > 0) and (height_ > 0));
}

double Rectangle::getArea() const
{
  return width_*height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Rectangle::move(point_t NewPoint)
{
  center_ = NewPoint;
}
