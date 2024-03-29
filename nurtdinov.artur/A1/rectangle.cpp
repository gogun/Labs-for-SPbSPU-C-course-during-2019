#include "rectangle.hpp"

#include <cassert>

Rectangle::Rectangle(const point_t &point, double width, double height) :
  position_(point),
  width_(width),
  height_(height)
{
  assert((width_ > 0.0) && (height_ > 0.0));
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, position_};
}

void Rectangle::move(const point_t &point)
{
  position_ = point;
}

void Rectangle::move(double dx, double dy)
{
  position_.x += dx;
  position_.y += dy;
}
