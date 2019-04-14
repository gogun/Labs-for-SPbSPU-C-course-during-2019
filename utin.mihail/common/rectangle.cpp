#include "rectangle.hpp"
#include <cassert>
#include <iostream>

utin::Rectangle::Rectangle(const utin::point_t &center, const double &width, const double &height):
  center_(center),
  width_(width),
  height_(height)
{
  assert((height > 0.0) && (width > 0.0));
}

double utin::Rectangle::getArea() const
{
  return width_ * height_;
}

utin::rectangle_t utin::Rectangle::getFrameRect() const
{
  return {center_, width_, height_};
}

void utin::Rectangle::move(const double &dx, const double &dy)
{
  center_.x += dx;
  center_.y += dy;
}

void utin::Rectangle::move(const point_t &point)
{
  center_ = point;
}

void utin::Rectangle::printInfo() const
{
  std::cout << "Width of rectangle is " << width_ << '\n'
            << "Height of rectangle is " << height_ << '\n'
            << "Center of rectangle is (" << center_.x << ";" << center_.y << ")" << '\n';
}
