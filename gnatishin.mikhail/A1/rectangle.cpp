#include "rectangle.hpp"

#include <cassert>

Rectangle::Rectangle(const point_t &pos, double width, double height) :
  center_(pos),
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
  return {width_, height_, center_};
}

point_t Rectangle::getPosition() const
{
  return center_;
}

void Rectangle::move(const point_t &center)
{
  center_ = center;
}

void Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}
