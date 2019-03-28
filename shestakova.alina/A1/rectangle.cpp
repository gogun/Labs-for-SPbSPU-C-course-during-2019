#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(point_t pos, double w, double h) :
  pos_(pos),
  width_(w),
  height_(h)
{
  assert((width_ > 0) && (height_ > 0));
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, pos_};
}

void Rectangle::move(const point_t &point)
{
  pos_ = point;
}

void Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y +=dy;
}
