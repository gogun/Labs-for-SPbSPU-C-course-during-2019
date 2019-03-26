#include "rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(const point_t &center, double height, double width):
  rectangle_({center, height, width})
{
  if ((rectangle_.height <= 0) || (rectangle_.width <= 0))
  {
    std::cerr << "Incorrect heigth or weight of rectangle" << std::endl;
  }
}

double Rectangle::getArea() const
{
  return rectangle_.height * rectangle_.width;
}

void Rectangle::move(double dx, double dy)
{
  rectangle_.pos.x += dx;
  rectangle_.pos.y += dy;
}

void Rectangle::move(const point_t &center)
{
  rectangle_.pos = center;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_;
}
