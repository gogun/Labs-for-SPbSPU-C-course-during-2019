#include "rectangle.hpp"

#include <stdexcept>

konev::Rectangle::Rectangle(const point_t &dot, double width, double height):
  center_(dot),
  width_(width),
  height_(height)
{
  if (width_ < 0.0)
  {
    throw std::invalid_argument("Rectangle width cannot be less than zero.");
  }
  if (height_ < 0.0)
  {
    throw std::invalid_argument("Rectangle height cannot be less than zero.");
  }
}

double konev::Rectangle::getArea() const
{
  return width_ * height_;
}

konev::rectangle_t konev::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void konev::Rectangle::move(const point_t &point)
{
  center_ = point;
}

void konev::Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void konev::Rectangle::scale(double coefficient)
{
  if (coefficient < 0.0)
  {
    throw std::invalid_argument("Rectangle scale coefficient cannot be less than zero.");
  }
  else
  {
    width_ *= coefficient;
    height_ *= coefficient;
  }
}
