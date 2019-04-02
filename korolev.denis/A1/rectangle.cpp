#include "rectangle.hpp"
#include <cassert>
#include <iostream>

Rectangle::Rectangle(const point_t &center, double wight, double height):
  center_(center),
  width_(wight),
  height_(height)
{
  assert((width_ > 0.0) && (height_ > 0.0));
}

Rectangle::Rectangle(double x, double y, double wight, double height):
  center_({x, y}),
  width_(wight),
  height_(height)
{
  assert((width_ > 0.0) && (height_ > 0.0));
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_t{center_, width_, height_};
}

void Rectangle::move(const point_t &position)
{
  center_ = position;
}

void Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Rectangle::printInf() const
{
  std::cout << "Parameters of rectangle: " << std::endl
    << "Center: (" << center_.x << ";" << center_.y << ")" << std::endl
    << "Width and height: " << width_ << " , " << height_ << std::endl
    << "Area: " << getArea() << std::endl;
}


