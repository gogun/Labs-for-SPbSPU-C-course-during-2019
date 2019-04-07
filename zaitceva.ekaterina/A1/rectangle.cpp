#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(double width, double height, point_t &pos):
  width_(width),
  height_(height),
  pos_(pos)

{
  assert((width_ > 0.0) && (height_ > 0.0));
}

double Rectangle::getArea() const
{
  return width_*height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, pos_};
}

void Rectangle::move(point_t &pos)
{
  pos_ = pos;
}

void Rectangle::move(double abs, double ord)
{
  pos_.x += abs;
  pos_.y += ord;
}
