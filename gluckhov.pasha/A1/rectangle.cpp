#include "rectangle.hpp"
#include <cassert>
#include <iostream>

Rectangle::Rectangle(double width, double height, const point_t &position):
  pos_(position),
  width_(width),
  height_(height)
{
  assert(width > 0.0);
  assert(height > 0.0);
}

double Rectangle::getArea() const
{
  return (width_ * height_);
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, pos_};
}

void Rectangle::printData() const
{
  std::cout << "Width: " << width_ << "\tHeight: " << height_;
  std::cout << "\nPosition: (" << pos_.x << ';' << pos_.y << ')';
}

void Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Rectangle::move(const point_t &newPos)
{
  pos_ = newPos;
}
