#include "rectangle.hpp"

#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t &position, const double width, const double height):
  Shape(position),
  width_(width),
  height_(height)
{
  assert(width_ > 0 && height_ > 0);
}

rectangle_t Rectangle::getFrameRect() const
{
  return { position_, width_, height_ };
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

void Rectangle::printInfo() const
{
  Shape::printInfo();
  std::cout << "\t width: " << width_ << " \t height: " << height_ << std::endl
      << "\t area: " << getArea() << std::endl
      << "\t frame:" << std::endl
      << "\t\tcenter: (" << getFrameRect().pos.x << ";" << getFrameRect().pos.y << ")" << std::endl
      << "\t\twidth: " << getFrameRect().width << "\theight: " << getFrameRect().height << std::endl
      << std::endl;
}
