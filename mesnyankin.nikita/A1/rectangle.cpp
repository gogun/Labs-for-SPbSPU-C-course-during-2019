#include "rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(const double width, const double height, const point_t pos):
  width_(width),
  height_(height),
  pos_(pos)
{
  if ((width <= 0) || (height <= 0)) {
    std::cerr << "Invalid width or height. Please input positive values next time!..";
  }
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

void Rectangle::move(const double x, const double y)
{
  pos_.x += x;
  pos_.y += y;
}

void Rectangle::move(const point_t point)
{
  pos_ = point;
}

double Rectangle::getWidth()
{
  return width_;
}

double Rectangle::getHeight()
{
  return height_;
}

point_t Rectangle::getPos()
{
  return pos_;
}

void Rectangle::showData()
{
  std::cout << "Rectangle data:" << std::endl;
  std::cout << "Width: " << width_ << std::endl;
  std::cout << "Height: " << height_ << std::endl;
  std::cout << "Centre position(x, y): " << pos_.x << "," << pos_.y << std::endl;
  std::cout << "FrameRect centre in: " << getFrameRect().pos.x << "," << getFrameRect().pos.y << std::endl;
  std::cout << "FrameRect width and height: " << getWidth() << " | " << getHeight() << std::endl;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {pos_, width_, height_};
}
