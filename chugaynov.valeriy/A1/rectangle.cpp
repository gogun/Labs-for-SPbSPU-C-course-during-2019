#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const double width, const double height, const point_t &point):
  width_(width),
  height_(height),
  pos_(point)
{
  assert((width > 0) && (height > 0));
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return { width_, height_, pos_ };
}

void Rectangle::move(const point_t &point)
{
  pos_ = point;
}

void Rectangle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
