#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t &center, const double width, const double height) :
  center_(center),
  width_(width),
  height_(height)
{
  assert((width_ > 0.0) && (height_ > 0.0));
}

rectangle_t Rectangle::getFrameRect() const
{
  return { center_, width_, height_ };
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

void Rectangle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Rectangle::move(const point_t &newPoint)
{
  center_ = newPoint;
}

void Rectangle::inform()
{
  std::cout << "X: " << center_.x;
  std::cout << "\n Y: " << center_.y;
}
