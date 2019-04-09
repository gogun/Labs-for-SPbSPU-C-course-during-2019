#include "rectangle.hpp"
#include <iostream>
#include <cassert>
#include "base-types.hpp"


gusarov::Rectangle::Rectangle(const point_t &center, const double width, const double height):
  width_(width),
  height_(height),
  center_(center)
{
  assert((height > 0) && (width > 0));
}
double gusarov::Rectangle::getArea() const
{
  return width_*height_;
}
gusarov::rectangle_t gusarov::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}
void gusarov::Rectangle::move(const double shiftX,const double shiftY)
{
  center_.x += shiftX;
  center_.y += shiftY;
}
void gusarov::Rectangle::move(const gusarov::point_t &newPoint)
{
  center_ = newPoint;
}
void gusarov::Rectangle::printInfo() const
{
  std::cout << "Width of rectangle is " << width_ <<'\n'
            << "Height of rectangle is " << height_ <<'\n'
            << "Center of rectangle is a point: ("<< center_.x<<";"<<center_.y<<")"<<'\n';
}
void gusarov::Rectangle::scale(double scale)
{
  assert(scale > 0);
  width_ *= scale;
  height_ *= scale;
}
