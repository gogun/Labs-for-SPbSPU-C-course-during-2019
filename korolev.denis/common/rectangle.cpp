#include "rectangle.hpp"

#include <stdexcept>

korolev::Rectangle::Rectangle(const point_t &center, double width, double height):
  center_(center),
  width_(width),
  height_(height)
{
  if ((width_ <= 0.0) || (height_ <= 0.0))
  {
    throw std::invalid_argument("Wight and height must be positive");
  }
}

korolev::Rectangle::Rectangle(double x, double y, double width, double height):
  center_({x, y}),
  width_(width),
  height_(height)
{
  if ((width_ <= 0.0) || (height_ <= 0.0))
  {
    throw std::invalid_argument("Wight and height must be positive");
  }
}

double korolev::Rectangle::getArea() const
{
  return width_ * height_;
}

korolev::rectangle_t korolev::Rectangle::getFrameRect() const
{
  return rectangle_t{ center_, width_, height_ };
}

void korolev::Rectangle::move(const point_t &position)
{
  center_ = position;
}

void korolev::Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void korolev::Rectangle::scale(double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Coefficient must be positive");
  }
  height_ *= coefficient;
  width_ *= coefficient;
}

