#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const point_t &center, const double &width, const double &height) :
  center_(center),
  width_(width),
  height_(height)
{
  assert((height_ > 0.0) && (width_ > 0.0));
}

double Rectangle::getArea() const
{
  return (width_ * height_);
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void Rectangle::move(const double &dx, const double &dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Rectangle::move(const point_t &newPoint)
{
  center_ = newPoint;
}
