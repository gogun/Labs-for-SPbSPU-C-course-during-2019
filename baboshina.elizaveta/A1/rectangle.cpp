#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const double width, const double height, const point_t pos):
  width_(width),
  height_(height),
  center_(pos)
{
  assert((width > 0) && (height > 0));
}

double Rectangle::getArea() const
{
  return height_ * width_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return { width_,height_,center_ };
}

void Rectangle::move(const point_t point)
{
  center_ = point;
}

void Rectangle::move(const double x, const double y)
{
  center_.x += x;
  center_.y += y;
}

void Rectangle::getInfo() const
{
  std::cout << "\nWidth of rectangle is: " << width_ << std::endl;
  std::cout << "Height of rectangle is: " << height_ << std::endl;
  std::cout << "Center of rectangle is: x=" << center_.x << " y=" << center_.y << std::endl;
}
