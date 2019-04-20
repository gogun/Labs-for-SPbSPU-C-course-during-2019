#include "rectangle.hpp"
#include <cassert>
#include <iostream>


Rectangle::Rectangle(const double width, const double height, const point_t &pos):
  width_(width),
  height_(height),
  pos_(pos)
{
  assert((width > 0) && (height > 0));
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

void Rectangle::move(const double x, const double y)
{
  pos_.x += x;
  pos_.y += y;
}

void Rectangle::move(const point_t &point)
{
  pos_ = point;
}

double Rectangle::getWidth()
{
  return width_;
}

double Rectangle::getHeight()
{
  return height_;
}

point_t Rectangle::getPos()
{
  return pos_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {pos_, width_, height_};
}
