#include <cassert>
#include <cmath>
#include "rectangle.hpp"

Rectangle::Rectangle(double height, double  width, const point_t & center):
  height_(height),
  width_(width),
  center_(center)
{
  assert((height > 0) && (width > 0));
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {height_, width_, center_};
}

void Rectangle::move(const point_t & point)
{
  center_ = point;
}

void Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}
