#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(point_t point, double w, double h):
center_(point),width_(w),height_(h)
{
  assert((width_ > 0) && (height_ > 0));
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

 void Rectangle::move(point_t point)
 {
   center_ = point;
 }

void Rectangle::move(double xx, double yy)
{
  center_.x += xx;
  center_.y += yy;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void Rectangle::printInfo() const
{
  std::cout << "Rectangle:";
  std::cout << " Width=" << getFrameRect().width << ";";
  std::cout << " Height=" << getFrameRect().height << std::endl;
  std::cout << "X=" << getFrameRect().pos.x << ";";
  std::cout << "Y=" << getFrameRect().pos.y << std::endl;
  std::cout << "Area=" << getArea() << std::endl << std::endl;
}
