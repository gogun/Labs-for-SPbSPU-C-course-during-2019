#include "rectangle.hpp"
#include <stdexcept>

andreeva::Rectangle::Rectangle(const point_t &point, double width, double height):
  center_(point),
  width_(width),
  height_(height)
{
  if (width_ < 0.0)
  {
    throw std::invalid_argument("Width cannot be negative");
  }
  if (height_ < 0.0)
  {
    throw std::invalid_argument("Height cannot be negative");
  }
}

double andreeva::Rectangle::getArea() const
{
  return width_ * height_;
}

andreeva::rectangle_t andreeva::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void andreeva::Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void andreeva::Rectangle::move(const point_t &point)
{
  center_ = point;
}

void andreeva::Rectangle::scale(double factor)
{
  if (factor > 0.0)
  {
    width_ *= factor;
    height_ *= factor;
  }
  else
  {
    throw std::invalid_argument("Factor cannot be negative");
  }
}
