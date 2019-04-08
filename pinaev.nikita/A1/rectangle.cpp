#include "rectangle.hpp"
#include "base-types.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t &centr, const double width, const double height):
  width_(width),
  height_(height),
  centr_(centr)
{
  assert(height > 0);
  assert(width > 0);
}
double Rectangle::getArea() const
{
  return width_ * height_;
}
rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, centr_};
}
void Rectangle::move(const double dx,const double dy)
{
  centr_.x += dx;
  centr_.y += dy;
}
void Rectangle::move(const point_t &newPoint)
{
  centr_ = newPoint;
}
void Rectangle::showResults() const
{
  std::cout << "Width is " << getFrameRect().width << std::endl
    << "Height is " << getFrameRect().height << std::endl
    << "Center at: (" << getFrameRect().pos.x << "; " << getFrameRect().pos.y << ")" << std::endl;
}
