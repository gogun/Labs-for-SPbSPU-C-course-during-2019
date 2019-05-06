#include "rectangle.hpp"

Rectangle::Rectangle(double width, double height, const point_t &center):
  width_(width),
  height_(height),
  center_(center)
{
  if (width_ <= 0.0) {
    throw std::invalid_argument("The specified rectangle's width is not valid.");
  }
  if (height_ <= 0.0) {
    throw std::invalid_argument("The specified rectangle's height is not valid.");
  }
}

void Rectangle::printInfo() const
{
  std::cout << "\nRectangle";
  std::cout << "\nWidth: " << width_;
  std::cout << "\nHeight: " << height_;
  std::cout << "\nCenter: " << center_.x << "; " << center_.y;
}

double Rectangle::getArea() const
{
  return (width_ * height_);
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void Rectangle::move(const point_t &newPos)
{
  center_ = newPos;
}

void Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}
