#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

sysoeva::Rectangle::Rectangle(double width, double height, const point_t &center):
  width_(width),
  height_(height),
  center_(center)
{
  if (width_ <= 0)
  {
    throw std::invalid_argument("Width has invalid value");
  }
  if (height_ <= 0)
  {
    throw std::invalid_argument("Height has invalid value");
  }
}

double sysoeva::Rectangle::getArea() const
{
  return width_ * height_;
}

sysoeva::rectangle_t sysoeva::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void sysoeva::Rectangle::move(const point_t &point)
{
  center_ = point;
}

void sysoeva::Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void sysoeva::Rectangle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Coefficient has invalid value");
  }
  width_ *= coefficient;
  height_ *= coefficient;
}
