#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const point_t &center, double height, double width) :
  center_(center),
  height_(height),
  width_(width)
{
  assert((height_ >= 0.0) && (width_ >= 0.0));
}

double Rectangle::getArea() const
{
  return (height_ * width_);
}

rectangle_t Rectangle::getFrameRect() const
{
  return { center_, height_, width_ };
}

void Rectangle::move(const point_t &newCenter)
{
  center_ = newCenter;
}

void Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

point_t Rectangle::getPos() const
{
  return center_;
}
