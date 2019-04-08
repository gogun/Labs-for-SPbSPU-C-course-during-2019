#include "rectangle.hpp"
#include <cassert>
#include <iostream>

Rectangle::Rectangle(const point_t &center, double width1, double height1):
  pos_(center),
  width_(width1),
  height_(height1)
{
  assert((width1 > 0) && (height1 > 0));
}

double Rectangle::getArea() const
{
  return(width_ * height_);
}

rectangle_t Rectangle::getFrameRect() const
{
  return{pos_, width_, height_};
}

void Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Rectangle::move(const point_t &pos1)
{
  pos_ = pos1;
}

void Rectangle::printInfo() const
{
  std::cout << "Area = " << getArea() << "\n"
            << "Width = " << width_ << ", height = " << height_ << "\n"
            << "Position (" << pos_.x << ", " << pos_.y << ")\n";
}
