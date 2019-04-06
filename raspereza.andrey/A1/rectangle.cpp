#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(point_t dot, double width, double height):
  center_(dot),
  width_(width),
  height_(height)
{
  assert((width_ >= 0.0) && (height_ >= 0.0));
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_,height_,center_};
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
