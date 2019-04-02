#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(double height, double wigth, const point_t &pos) :
  pos_(pos),
  height_(height),
  wigth_(wigth)
{
  assert((height_ > 0.0) && (wigth_ > 0.0));
}

double Rectangle::getArea() const
{
  double area = height_ * wigth_;
  return area;
}

void Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Rectangle::move(const point_t &center)
{
  pos_.x = center.x;
  pos_.y = center.y;
}

rectangle_t Rectangle::getFrameRect() const
{
  rectangle_t frame;
  frame.height = height_;
  frame.wigth = wigth_;
  frame.pos = pos_;
  return frame;
}

void Rectangle::showPoint() const
{
  std::cout << "the point on the x-axis " << pos_.x << "\n";
  std::cout << "the point on the y-axis " << pos_.y << "\n";
}
