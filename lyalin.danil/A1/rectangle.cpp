#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(point_t position, double width, double height) :
  center_(position),
  width_(width),
  height_(height)
{
  assert((width_ >= 0.0) and (height_ >= 0.0));
}

Rectangle::Rectangle(double x, double y, double width, double height) :
  Rectangle({x, y}, width, height)
{
}

Rectangle::Rectangle(point_t position, double side) :
  Rectangle(position, side, side)
{
}

Rectangle::Rectangle(double x, double y, double side) :
  Rectangle({x, y}, side, side)
{
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void Rectangle::move(double dx, double dy)
{
  center_.x = dx;
  center_.y = dy;
}

void Rectangle::move(const point_t &position)
{
  center_ = position;
}
