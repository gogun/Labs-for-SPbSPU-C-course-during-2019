#include "rectangle.hpp"
#include <iostream>
#include <cassert>
#include "base-types.hpp"

Rectangle::Rectangle(point_t pos, double width, double height) :
  topLeftPoint_(pos),
  width_(width),
  height_(height)
{
  assert((width > 0.0) && (height > 0.0));
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return { topLeftPoint_, width_, height_ };
}

void Rectangle::move(const double newX, const double newY)
{
  topLeftPoint_.x += newX;
  topLeftPoint_.y += newY;
}

void Rectangle::move(const point_t & point)
{
  topLeftPoint_ = point;
}

void Rectangle::dataOutput() const
{
  std::cout << "Rectangle's TOP LEFT CORNER: " << topLeftPoint_.x << " " << topLeftPoint_.y << '\n'
    << "Rectangle's WIDTH: " << width_ << '\n'
    << "Rectangle's HEIGHT: " << height_ << '\n';
}
