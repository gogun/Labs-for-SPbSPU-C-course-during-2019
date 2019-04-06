#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t pos, double height, double width):
  pos_(pos),
  height_(height),
  width_(width)
{
  assert((height > 0.0) && (width > 0.0));
}

double  Rectangle::getArea() const
{
  return (width_ * height_);
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, pos_};
}

void Rectangle::move(const point_t &point)
{
  pos_ = point;
}

void Rectangle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Rectangle::print() const
{
  std::cout << "Area: " << getArea() << std::endl;
  std::cout << "Height: " << height_ << std::endl;
  std::cout << "Width: " << width_ << std::endl;
  std::cout << "Center position x = " << pos_.x << std::endl;
  std::cout << "Center position y = " << pos_.y << std::endl;
  rectangle_t frame = getFrameRect();
  std::cout << "Rectangle frame: " << std::endl;
  std::cout << "Height: " << frame.height << std::endl;
  std::cout << "Width: " << frame.width << "\n\n";
}
