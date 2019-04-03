#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle (double width, double height, point_t pos):
  Shape(pos),
  width_(width),
  height_(height)
{
  assert(width > 0.0);
  assert(height > 0.0);
}

void Rectangle::displayData() const
{
  std::cout << "\nWidth: " << width_ << std::endl
    <<"Height: " << height;
  Shape::displayData();
}

double Rectangle::getArea() const
{
  return (width_ * height);
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_t{width_, height, {m_pos.x, m_pos.y}};
}
