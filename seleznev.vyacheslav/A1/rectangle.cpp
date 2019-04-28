#include "rectangle.hpp"

#include <cassert>

Rectangle::Rectangle(double w, double h, const point_t& pos):
  centre_(pos),
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

void Rectangle::move(const point_t& point)
{
  centre_ = point;
}

void Rectangle::move(const double dx, const double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}
