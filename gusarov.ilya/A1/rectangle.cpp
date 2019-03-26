#include <iostream>
#include "rectangle.hpp"
#include "base-types.hpp"

Rectangle::Rectangle(const point_t &center, double width, double height):
  width_(width),
  height_(height),
  center_(center)
{

}
double Rectangle::getArea() const
{
  return width_*height_;
}
rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}
void Rectangle::move(double shiftX, double shiftY)
{
  center_.x += shiftX;
  center_.y += shiftY;
}
void Rectangle::move(point_t newPoint)
{
  center_ = newPoint;
}
void Rectangle::printInfo()
{
  std::cout << "Width of rectangle is " << width_ <<'\n'
            << "Height of rectangle is " << height_ <<'\n'
            << "Center of rectangle is a point: ("<< center_.x<<";"<<center_.y<<")"<<'\n';
}
