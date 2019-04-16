#include "rectangle.hpp"
#include <cassert>
#include <iostream>

Rectangle::Rectangle(double width, double height, const point_t & center):
  width_(width),
  height_(height),
  center_(center)

{
  assert((height > 0.0) && (width > 0.0));
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void Rectangle::move(const point_t & point)
{
  center_ = point;
}

void Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}
