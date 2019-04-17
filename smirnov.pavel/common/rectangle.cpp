#include "rectangle.hpp"
#include <cassert>
#include <iostream>

smirnov::Rectangle::Rectangle(double width, double height, const point_t & center):
  width_(width),
  height_(height),
  center_(center)
{
  if ((width_ <= 0) || (height_ <= 0))
  {
    throw std::invalid_argument("Width and height must be positive. ");
  }
}

double smirnov::Rectangle::getArea() const
{
  return width_ * height_;
}

smirnov::rectangle_t smirnov::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void smirnov::Rectangle::move(const point_t & new_point)
{
  center_ = new_point;
}

void smirnov::Rectangle::move(double x_delta, double y_delta)
{
  center_.x += x_delta;
  center_.y += y_delta;
}

void smirnov::Rectangle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Coefficient must be positive. ");
  }
  width_ *= coefficient;
  height_ *= coefficient;
}

void smirnov::Rectangle::getInfo() const
{
  std::cout << "Area of rectangle is " << getArea() << "\n";
  std::cout << "Width of rectangle is " << width_ << "\n";
  std::cout << "Height of rectangle is " << height_ << "\n";
  std::cout << "Center of rectangle is (" << center_.x << ";" << center_.y << ")\n";
}
