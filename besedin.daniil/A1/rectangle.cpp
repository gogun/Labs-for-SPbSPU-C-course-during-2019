#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const double width, const double height, const point_t &center) :
  width_(width),
  height_(height),
  center_(center)
{
  assert((width_ > 0.0) && (height_ > 0.0));
}

double Rectangle::getArea() const noexcept
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const noexcept
{
  return {width_, height_, center_};
}

void Rectangle::move(const double dx, const double dy) noexcept
{
  center_.x += dx;
  center_.y += dy;
}

void Rectangle::move(const point_t &newPos) noexcept
{
  center_ = newPos;
}
