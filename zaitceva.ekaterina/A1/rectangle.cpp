#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(double width, double height, const point_t &centre):
  width_(width),
  height_(height),
  centre_(centre)
{
  assert((width_ > 0.0) && (height_ > 0.0));
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, centre_};
}

void Rectangle::move(const point_t &point)
{
  centre_ = point;
}

void Rectangle::move(double dx, double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}
