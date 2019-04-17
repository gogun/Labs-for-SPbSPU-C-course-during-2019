#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t &center, double height, double width) :
  center_(center),
  height_(height),
  width_(width)
{
  assert((height_ >= 0.0) && (width_ >= 0.0));
}

double Rectangle::getArea() const
{
  return height_ * width_;
}

void Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Rectangle::move(const point_t &center)
{
  center_ = center;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {center_, height_, width_};
}

void Rectangle::showPoint() const
{
  std::cout << "the point on the x-axis " << center_.x << "\n";
  std::cout << "the point on the y-axis " << center_.y << "\n";
}
