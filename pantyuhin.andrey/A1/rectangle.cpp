#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(point_t centre, double width, double height):
  centre_(centre),
  width_(width),
  height_(height)
{
  assert((width_ > 0) && "width of rectangle can't be <= 0");
  assert((height_ > 0) && "height of rectangle can't be <= 0");
}

Rectangle::Rectangle(double x, double y, double width, double height):
  Rectangle({x, y}, width, height)
{ }

void Rectangle::printParameters() const
{
  std::cout << "rectangle: x = " << centre_.x << ", y = " << centre_.y << ", width = "
      << width_ << ", height = " << height_ << std::endl << std::endl;
}

double Rectangle::getArea() const
{
  return (width_ * height_);
}

rectangle_t Rectangle::getFrameRect() const
{
  return {centre_, width_, height_};
}

void Rectangle::move(double dx, double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}

void Rectangle::move(point_t centre)
{
  centre_ = centre;
}
