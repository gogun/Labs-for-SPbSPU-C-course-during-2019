#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t &centre, double width, double height) :
  position_(centre),
  width_(width),
  height_(height)
{
  assert(width >= 0 || height >= 0);
}

double Rectangle::getArea() const
{
  return height_ * width_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_t {width_, height_,{position_.x, position_.y}};
}

void Rectangle::move(double dx, double dy)
{
  position_.x += dx;
  position_.y += dy;
}

void Rectangle::move(const point_t &param)
{
  position_ = param;
}

void Rectangle::printInfo() const
{
  rectangle_t info = getFrameRect();
  std::cout << "Area = " << getArea() << std::endl;
  std::cout << "Central coordinates of frame rectangle: (" << info.pos.x << ", " << info.pos.y << ")" << std::endl;
  std::cout << "Frame width = " << info.width <<", frame height = " << info.height << std::endl;
  std::cout << std::endl;
}
