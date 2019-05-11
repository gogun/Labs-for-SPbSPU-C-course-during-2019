#include "rectangle.hpp"

#include <iostream>
#include <stdexcept>

chizhov::Rectangle::Rectangle(point_t position, double width, double height) :
    center_(position),
    width_(width),
    height_(height)
{
  if ((width_ <= 0) || (height_ <= 0)) {
    throw std::invalid_argument("Dimensions must be positive");
  }
}

chizhov::Rectangle::Rectangle(double x, double y, double width, double height) :
    Rectangle(point_t{x, y}, width, height)
{ }

chizhov::Rectangle::Rectangle(point_t position, double side) :
    Rectangle(position, side, side)
{ }

chizhov::Rectangle::Rectangle(double x, double y, double side) :
    Rectangle(point_t{x, y}, side, side)
{ }

double chizhov::Rectangle::getArea() const
{
  return width_ * height_;
}

chizhov::rectangle_t chizhov::Rectangle::getFrameRect() const
{
  return rectangle_t{width_, height_, center_};
}

void chizhov::Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void chizhov::Rectangle::move(point_t position)
{
  center_ = position;
}

void chizhov::Rectangle::scale(double scale)
{
  if (scale <= 0) {
    throw std::invalid_argument("You cannot scale by non-positive multiplier");
  }

  width_ *= scale;
  height_ *= scale;
}
