#include "rectangle.hpp"
#include <iostream>
#include <cassert>
#include "base-types.hpp"


Rectangle::Rectangle(const point_t &center, const double width, const double height):
  width_(width),
  height_(height),
  center_(center)
{
  assert((height > 0) && (width > 0));
}
double Rectangle::getArea() const
{
  return width_*height_;
}
rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}
void Rectangle::move(const double shiftX,const double shiftY)
{
  center_.x += shiftX;
  center_.y += shiftY;
}
void Rectangle::move(const point_t &newPoint)
{
  center_ = newPoint;
}
void Rectangle::printInfo() const
{
  std::cout << "Width of rectangle is " << width_ <<'\n'
            << "Height of rectangle is " << height_ <<'\n'
            << "Center of rectangle is a point: ("<< center_.x<<";"<<center_.y<<")"<<'\n';
}
