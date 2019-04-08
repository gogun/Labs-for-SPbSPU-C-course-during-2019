#include "rectangle.hpp"
#include <cassert>
#include <iostream>

Rectangle::Rectangle(const point_t &center,
    double width, double height):
  Shape(center),
  width_(width),
  height_(height)
  {
    assert((width_ >= 0) &&  (height_ >= 0) && ("Invalid values"));
  }

double Rectangle::getWidth() const
{
  return width_;
}

double Rectangle::getHeight() const
{
  return height_;
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void Rectangle::printSpec() const
{
  std::cout << "Area is " << getArea() << " square units\n";
  rectangle_t frameRectangle = getFrameRect();
  std::cout << "Frame rectangle width = " << frameRectangle.width << std::endl;
  std::cout << "Frame rectangle height = " << frameRectangle.height << std::endl;
  std::cout << "Frame rectangle center X: " << frameRectangle.pos.x << "; ";
  std::cout << "Frame rectangle center Y: " << frameRectangle.pos.y << std::endl;
}
