#include <stdexcept>
#include "rectangle.hpp"

Rectangle::Rectangle(double width, double height, point_t center) :
  width_(width),
  height_(height),
  center_(center)
{

  if (width_ < 0.0 || height < 0.0)
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
  rectangle_t frame = {width_, height_, center_};
  return frame;
}

void Rectangle::move(double dx, double dy) noexcept
{
  center_.x += dx;
  center_.y += dy;
}

void Rectangle::move(point_t newPos) noexcept
{
  center_ = newPos;
}