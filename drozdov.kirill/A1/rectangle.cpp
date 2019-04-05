#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle (double width, double height, const point_t &pos):
  width_(width),
  height_(height),
  pos_(pos)
{
  assert(width > 0.0);
  assert(height > 0.0);
}

void Rectangle::displayData() const
{
  std::cout << "\nWidth: " << width_ << std::endl
    <<"Height: " << height_
      << "\nPosition: (" << pos_.x << ';' << pos_.y << ')';
}

double Rectangle::getArea() const
{
  return (width_ * height_);
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_t{width_, height_, {pos_.x, pos_.y}};
}

void Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Rectangle::move(const point_t &dot)
{
  pos_ = dot;
}
