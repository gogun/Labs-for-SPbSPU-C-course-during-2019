#include "rectangle.hpp"
#include <stdexcept>

Rectangle::Rectangle(double width, double height, const point_t &center) :
  width_(width),
  height_(height),
  center_(center)
{
  if ((width_ < 0.0) || (height_ < 0.0))
  {
    throw std::invalid_argument("Invalid parameters");
  }
}

double Rectangle::getArea() const noexcept
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const noexcept
{
  return {width_, height_, center_};
}

void Rectangle::move(const double dx, const double dy) noexcept
{
  center_.x += dx;
  center_.y += dy;
}

void Rectangle::move(const point_t &newPos) noexcept
{
  center_ = newPos;
}
