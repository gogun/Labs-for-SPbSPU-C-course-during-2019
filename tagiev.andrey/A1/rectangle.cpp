#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const point_t &center, double width, double height) :
  center_(center),
  width_(width),
  height_(height)
{
  assert((height > 0) && (width > 0));
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
  center_.x += dx;
  center_.y += dy;
}
void Rectangle::move(const point_t &newPoint)
{
  center_ = newPoint;
}
