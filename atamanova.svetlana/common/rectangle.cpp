#include "rectangle.hpp"
#include <iostream>
#include <cassert>

atamanova::Rectangle::Rectangle(point_t center, double width, double height) :
  center_(center),
  width_(width),
  height_(height)
{
  if (width_ <= 0.0)
  {
    throw std::invalid_argument("Rectangle width is less or equal zero.");
  }
  if (height_ <= 0.0)
  {
    throw std::invalid_argument("Rectangle height is less or equal zero.");
  }
}


double atamanova::Rectangle::getArea() const
{
  return width_ * height_;
}

atamanova::rectangle_t atamanova::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void atamanova::Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void atamanova::Rectangle::move(point_t point)
{
  center_ = point;
}

void atamanova::Rectangle::scale(double scale)
{
  if (scale <= 0)
  {
    throw std::invalid_argument("Scale is less or equal 0");
  }
  else
  {
    width_ *= scale;
    height_ *= scale;
  }
}
