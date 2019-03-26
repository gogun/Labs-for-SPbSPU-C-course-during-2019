#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(point_t pos, double width, double height):
  pos_(pos),
  width_(width),
  height_(height)
{
  assert((width > 0) || (height > 0));
}

Rectangle::Rectangle(point_t pos, double width):
  pos_(pos),
  width_(width),
  height_(width)
{
 assert(width > 0);
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {pos_,width_,height_};
}

void Rectangle::move(point_t point)
{
  pos_ = point;
}

void Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
