#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(point_t position, double width, double height):
  position_(position),
  width_(width),
  height_(height)
{
  assert((width > 0) && (height > 0));
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {position_, width_, height_};
}

void Rectangle::move(point_t newPosition)
{
  position_ = newPosition;
}

void Rectangle::move(double dx, double dy)
{
  position_.x += dx;
  position_.y += dy;
}
