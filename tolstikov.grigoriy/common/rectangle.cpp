#include "rectangle.hpp"
#include <stdexcept>

tolstikov::Rectangle::Rectangle(point_t pos, double width, double height):
  pos_(pos),
  width_(width),
  height_(height)
{
  if ((width <= 0) || (height <= 0)) {
    throw std::invalid_argument("Width and height must be a positive number!\n");
  }
}

tolstikov::Rectangle::Rectangle(point_t pos, double width):
  pos_(pos),
  width_(width),
  height_(width)
{
  if (width <= 0) {
    throw std::invalid_argument("Width must be a positive number!\n");
  }
}

double tolstikov::Rectangle::getArea() const
{
  return width_ * height_;
}

tolstikov::rectangle_t tolstikov::Rectangle::getFrameRect() const
{
  return { pos_, width_, height_ };
}

void tolstikov::Rectangle::scale(double scaleFactor)
{
  if (scaleFactor <= 0) {
    throw std::invalid_argument("Factor of sacle must be a positive number!\n");
  }
  width_ *= scaleFactor;
  height_ *= scaleFactor;
}

void tolstikov::Rectangle::move(point_t point)
{
  pos_ = point;
}

void tolstikov::Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
