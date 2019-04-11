#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(double height, double width, const point_t &pos) :
  height_(height),
  width_(width),
  pos_(pos)
{
  assert((height_ > 0.0) && (width_ > 0.0));
}

double Rectangle::getArea() const
{
  return height_ * width_;
}

void Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Rectangle::move(const point_t &center)
{
  pos_ = center;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {height_, width_, {pos_.x, pos_.y}};
}

void Rectangle::showPoint() const
{
  std::cout << "the point on the x-axis " << pos_.x << "\n";
  std::cout << "the point on the y-axis " << pos_.y << "\n";
}

