#include "rectangle.hpp"
#include <cassert>
#include <iostream>

Rectangle::Rectangle(const point_t &center, const double &width, const double &height):
  center_(center),
  width_(width),
  height_(height)
{
  assert((height > 0)&&(width > 0));
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return { center_, width_, height_};
}

void Rectangle::move(const double &dx, const double &dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Rectangle::move(const point_t &point)
{
  center_ = point;
}

void Rectangle::printInfo() const
{
  std::cout << "Width of rectangle is " << width_ << '\n'
            << "Height of rectangle is " << height_ << '\n'
            << "Center of rectangle is (" << center_.x << ";" << center_.y << ")" << '\n';
}
