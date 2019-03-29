#include "rectangle.hpp"

#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t &position, double width, double height):
  Shape(position),
  width_(width),
  height_(height)
{
  assert(width_ > 0 && height_ > 0);
}

rectangle_t Rectangle::getFrameRect() const
{
  return{ position_, width_, height_ };
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

void Rectangle::printInfo() const
{
  Shape::printInfo();
  std::cout << "\t width: " << width_ << " \t height: " << height_ << std::endl;
  std::cout << "\t area: " << getArea() << std::endl;

  std::cout << "\t frame:" << std::endl;
  std::cout << "\t\tcenter: (" << getFrameRect().pos.x << ";" << getFrameRect().pos.y << ")" << std::endl;
  std::cout << "\t\twidth: " << getFrameRect().width << "\theight: " << getFrameRect().height << std::endl;
  std::cout << std::endl;
}
