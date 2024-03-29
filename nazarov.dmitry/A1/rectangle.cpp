#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t &pos, const double &width, const double &height) :
  Shape(pos), 
  width_(width), 
  height_(height)
{
  assert((width_ >= 0.0) && (height >= 0.0));
}

Rectangle::Rectangle(const double &x, const double &y, const double &width, const double &height) :
  Rectangle({x, y}, width, height)
{ }

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {pos_, width_, height_};
}

void Rectangle::printFeatures() const
{
  std::cout << "Rectangle information:\nWidth: " << width_ << "\nHeight: " << height_ << "\n";
}
