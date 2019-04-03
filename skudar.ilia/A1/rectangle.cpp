#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(point_t pos, double width, double height):
  center_(pos),
  width_(width),
  height_(height)
{
  assert((width_ > 0.0) && (height_ > 0.0));
}

Rectangle::Rectangle(double x, double y, double width, double height):
  Rectangle({x, y}, width, height)
{
  assert((width_ > 0.0) && (height_ > 0.0));
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

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {center_, width_, height_};
}
