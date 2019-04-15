#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(double width, double height, const point_t &center) :
  width_(width),
  height_(height),
  pos_(center)
{
  assert((width > 0.0) && (height > 0.0));
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, pos_};
}

void Rectangle::move(const point_t &pos)
{
  pos_ = pos;
}

void Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Rectangle::printInfo() const
{
  std::cout << "Rectangle:"
      << std::endl << "  Width: " << width_
      << std::endl << "  Height: " << height_
      << std::endl << "  Position: "
      << std::endl << "    x: " << pos_.x
      << std::endl << "    y: " << pos_.y
      << std::endl << "  Area: " << this->getArea()
      << std::endl << std::endl;
}
