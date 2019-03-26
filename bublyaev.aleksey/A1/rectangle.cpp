#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t &center, double width, double height) :
  center_(center),
  width_(width),
  height_(height)
{
  assert ((width > 0.0) && (height > 0.0));
}

double Rectangle::getArea() const
{
  return width_ * height_;
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

void Rectangle::printInfo() const
{
  std::cout << "Rectangle:\nCenter coordinates: (" << center_.x << " , " << center_.y << ")" << std::endl;
  std::cout << "Width: " << width_ << std::endl;
  std::cout << "Height: " << height_ << std::endl;
  std::cout << "Area: " << getArea() << std::endl;
}
