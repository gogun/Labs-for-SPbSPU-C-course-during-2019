#include "rectangle.hpp"
#include <iostream>

utin::Rectangle::Rectangle(const utin::point_t &center, const double &width, const double &height):
  center_(center),
  width_(width),
  height_(height)
{
  if (height_ <= 0.0)
  {
    throw std::invalid_argument("Height must be greater that zero");
  }
  if (width_ <= 0.0)
  {
    throw std::invalid_argument("Width must be greater that zero");
  }
}

double utin::Rectangle::getArea() const
{
  return width_ * height_;
}

utin::rectangle_t utin::Rectangle::getFrameRect() const
{
  return {center_, width_, height_};
}

void utin::Rectangle::move(const double &dx, const double &dy)
{
  center_.x += dx;
  center_.y += dy;
}

void utin::Rectangle::move(const point_t &point)
{
  center_ = point;
}

void utin::Rectangle::scale(double multiplier)
{
  if (multiplier <= 0)
  {
    throw std::invalid_argument("Multiplier must be greater that zero");
  }
  width_ *= multiplier;
  height_ *=multiplier;
}

void utin::Rectangle::printInfo() const
{
  std::cout << "Width of rectangle is " << width_ << '\n'
            << "Height of rectangle is " << height_ << '\n'
            << "Center of rectangle is (" << center_.x << ";" << center_.y << ")" << '\n';
}
