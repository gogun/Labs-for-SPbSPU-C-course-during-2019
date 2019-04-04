#include "rectangle.hpp"

Rectangle::Rectangle(double width, double height, point_t pos):
  width_(width),
  height_(height),
  pos_(height)
{}

double Rectangle::getArea() const
{
  return (width_ * height_);
}

rectangle_t Rectangle::getFrameRect() const
{
  rectangle_t frameRect = {width_, height_, {pos_.x, pos_.y}};
  return frameRect;
}

void Rectangle::move (double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Rectangle::move (point_t newPos)
{
  pos_ = newPos;
}
