#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(double width, double height, const point_t position):
  width_(width),
  height_(height),
  pos_(position)
{
  assert ((height > 0.0) && (width > 0.0));

}

double Rectangle::getArea() const
{
  return (width_ * height_);
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, pos_};
}

void Rectangle::move(const point_t& point)
{
  pos_ = point;
}

void Rectangle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Rectangle::printShapeInfo() const
{
  std::cout << "Width: " << width_ << std::endl;
  std::cout << "Height: " << height_ << std::endl;
  std::cout << "Center position: x = " << pos_.x << ", y = " << pos_.y << std::endl;
  std::cout << "Area: " << getArea() << std::endl;
  rectangle_t frame = getFrameRect();
  std::cout << "Rectangle frame: " << std::endl;
  std::cout << "Width: " << frame.width << std::endl;
  std::cout << "Height: " << frame.height << "\n\n";

}
