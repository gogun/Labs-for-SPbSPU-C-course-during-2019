#include <cassert>
#include "rectangle.hpp"

Rectangle::Rectangle(point_t point, double width, double height):
center_(point),
width_(width),
height_(height)
{
  assert((width_ >= 0.0)&&(height_ >= 0.0));
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void Rectangle::move(const point_t point)
{
  center_ = point;
}

void Rectangle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}
