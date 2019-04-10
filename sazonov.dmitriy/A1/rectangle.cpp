#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(double height, double width, const point_t &center) :
  height_(height),
  width_(width),
  center_(center)
{
  assert((width_ >= 0.0) && (height_ >= 0.0));
}

double Rectangle::getArea() const
{
  return height_ * width_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return { height_, width_, center_ };
}

void Rectangle::move(const point_t &newPos)
{
  center_ = newPos;
}

void Rectangle::move(double ax, double ay)
{
  center_.x += ax;
  center_.y += ay;
}

point_t Rectangle::getPos() const
{
  return center_;
}
