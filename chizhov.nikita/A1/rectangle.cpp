#include "rectangle.hpp"

#include <iostream>

Rectangle::Rectangle(point_t pos, double w, double h) : center_(pos),
    width_(w),
    height_(h),
{
  if ((width_ <= 0) || (height_ <= 0)) {
    std::cerr << "Rectangle: Invalid dimensions\n";
  }
}

Rectangle::Rectangle(double x, double y, double w, double h) : Rectangle({x, y}, w, h)
{ }

Rectangle::Rectangle(point_t pos, double a) : Rectangle(pos, a, a)
{ }

Rectangle::Rectangle(double x, double y, double a) : Rectangle({x, y}, a, a)
{ }

Rectangle::Rectangle() : center_({0, 0}),
    width_(0),
    height_(0),
{ }

void Rectangle::move(point_t point)
{
  center_ = point;
}

void Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  rectangle_t tmp = {width_, height_, center_};
  return tmp;
}
